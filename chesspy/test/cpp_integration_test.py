import unittest, json, pathlib, logging, sys
from chesscpp import generate_moves
from chesspy.game import import_fen


class CPPIntegration(unittest.TestCase):
    def test_move_generator(self):
        log = logging.getLogger("tests.testMoveGenerator")
        test_dir = pathlib.Path(__file__).parent.resolve()
        log.debug(test_dir)
        with open(f"{test_dir}/data/test_data_all_fen_matches.json") as f:
            test_cases = json.loads(f.read())
        i, n_test_cases = 0, len(test_cases.items())
        log.debug(f"Found {n_test_cases} test cases.")
        for fen, solution in test_cases.items():
            log.debug(f"Testing Case {i+1}/{n_test_cases}: {fen}")
            board = import_fen(fen)
            uci_moves = generate_moves(
                board.board_state,
                board.to_move,
                board.en_passant_tile,
                *board.can_castle,
                board.n_reversible_halfmoves,
                board.n_moves,
            )

            uci_moves_list = sorted(uci_moves)
            n_moves = len(uci_moves_list)

            true_n_legal_moves = solution["n_legal_moves"]
            true_moves_list = sorted(solution["legal_moves"])

            if true_n_legal_moves != n_moves:
                print(
                    board.board_state,
                    board.to_move,
                    board.en_passant_tile,
                    *board.can_castle,
                    board.n_reversible_halfmoves,
                    board.n_moves,
                )
                print(true_moves_list)
                print(uci_moves_list)
                print(board.board_state)
                import pdb

                pdb.set_trace()

            self.assertEqual(true_n_legal_moves, n_moves)
            self.assertListEqual(true_moves_list, uci_moves_list)
            i += 1


if __name__ == "__main__":
    logging.basicConfig(stream=sys.stderr)
    # uncomment for debugging
    logging.getLogger("tests.testMoveGenerator").setLevel(logging.DEBUG)
    unittest.main()
