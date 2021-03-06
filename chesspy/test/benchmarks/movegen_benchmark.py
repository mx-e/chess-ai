import sys, time
from chesspy.game import import_fen
from chesscpp import generate_moves, generate_moves_benchmark
from benchmark_utils import get_random_positions, write_benchmark_results

N_REPEATS = 10000
N_POSITIONS = 500
RANDOM_SEED = 329
OUTNAME = "results_movegen_benchmark.csv"


nanoseconds_in_second = 1e9

if __name__ == "__main__":
    RunName = sys.argv[1]
    assert type(RunName) is str
    overwrite_csv = False if len(sys.argv) == 2 else bool(sys.argv[2])
    assert type(overwrite_csv) is bool

    Positions = get_random_positions(RANDOM_SEED, N_POSITIONS)
    results = (
        [["run_name", "position", "time_passed_ns", "n_moves", "moves"]]
        if overwrite_csv
        else []
    )

    for position in Positions:
        board = import_fen(position)
        moves = generate_moves(
            board.board_state,
            board.to_move,
            board.en_passant_tile,
            *board.can_castle,
            board.n_reversible_halfmoves,
            board.n_moves
        )
        n_moves = len(moves)
        start = time.time()
        generate_moves_benchmark(
            board.board_state,
            board.to_move,
            board.en_passant_tile,
            *board.can_castle,
            board.n_reversible_halfmoves,
            board.n_moves,
            N_REPEATS
        )
        time_passed = (time.time() - start) * (nanoseconds_in_second / N_REPEATS)
        result = [RunName, position, time_passed, n_moves, moves]
        results.append(result)
    write_benchmark_results(outname=OUTNAME, results=results, overwrite=overwrite_csv)
