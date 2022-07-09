#ifndef PSTABLES_H
#define PSTABLES_H

#include <vector>
#include "utils.hpp"

const std::vector<std::vector<float>> PSTABLES = {
    // King
    {-30, -40, -40, -50, -50, -40, -40, -30,
     -30, -40, -40, -50, -50, -40, -40, -30,
     -30, -40, -40, -50, -50, -40, -40, -30,
     -30, -40, -40, -50, -50, -40, -40, -30,
     -20, -30, -30, -40, -40, -30, -30, -20,
     -10, -20, -20, -20, -20, -20, -20, -10,
     20, 20, 0, 0, 0, 0, 20, 20,
     30, 30, 20, 20, 20, 30, 30, 30},

    // Queen
    {-20, -10, -10, -5, -5, -10, -10, -20,
     -10, 0, 0, 0, 0, 0, 0, -10,
     -10, 0, 5, 5, 5, 5, 0, -10,
     -5, 0, 5, 5, 5, 5, 0, -5,
     0, 0, 5, 5, 5, 5, 0, -5,
     -10, 5, 5, 5, 5, 5, 0, -10,
     -10, 0, 5, 0, 0, 0, 0, -10,
     -20, -10, -10, -5, -5, -10, -10, -20},

    // Bishop
    {-20, -10, -10, -10, -10, -10, -10, -20,
     -10, 0, 0, 0, 0, 0, 0, -10,
     -10, 0, 5, 10, 10, 5, 0, -10,
     -10, 5, 5, 10, 10, 5, 5, -10,
     -10, 0, 10, 10, 10, 10, 0, -10,
     -10, 10, 10, 10, 10, 10, 10, -10,
     -10, 5, 0, 0, 0, 0, 5, -10,
     -20, -10, -10, -10, -10, -10, -10, -20},

    // Knight
    {-50, -40, -30, -30, -30, -30, -40, -50,
     -40, -20, 0, 0, 0, 0, -20, -40,
     -30, 0, 10, 15, 15, 10, 0, -30,
     -30, 5, 15, 20, 20, 15, 5, -30,
     -30, 0, 15, 20, 20, 15, 0, -30,
     -30, 5, 10, 15, 15, 10, 5, -30,
     -40, -20, 0, 5, 5, 0, -20, -40,
     -50, -40, -30, -30, -30, -30, -40, -50},

    // Rook
    {0, 0, 0, 0, 0, 0, 0, 0,
     5, 0, 0, 0, 0, 0, 0, 5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     0, 0, 0, 5, 5, 0, 0, 0},

    // Pawn
    {0, 0, 0, 0, 0, 0, 0, 0,
     50, 50, 50, 50, 50, 50, 50, 50,
     10, 10, 20, 30, 30, 20, 10, 10,
     5, 5, 10, 25, 25, 10, 5, 5,
     0, 0, 0, 20, 20, 0, 0, 0,
     5, -5, -10, 0, 0, -10, -5, 5,
     5, 10, 10, -20, -20, 10, 10, 5,
     0, 0, 0, 0, 0, 0, 0, 0},

    // King
    {-50, -40, -30, -20, -20, -30, -40, -50,
     -30, -20, -10, 0, 0, -10, -20, -30,
     -30, -10, 20, 30, 30, 20, -10, -30,
     -30, -10, 30, 40, 40, 30, -10, -30,
     -30, -10, 30, 40, 40, 30, -10, -30,
     -30, -10, 20, 30, 30, 20, -10, -30,
     -30, -30, 0, 0, 0, 0, -30, -30,
     -50, -30, -30, -30, -30, -30, -30, -50},

    // Queen
    {-20, -10, -10, -5, -5, -10, -10, -20,
     -10, 0, 0, 0, 0, 0, 0, -10,
     -10, 0, 5, 5, 5, 5, 0, -10,
     -5, 0, 5, 5, 5, 5, 0, -5,
     0, 0, 5, 5, 5, 5, 0, -5,
     -10, 5, 5, 5, 5, 5, 0, -10,
     -10, 0, 5, 0, 0, 0, 0, -10,
     -20, -10, -10, -5, -5, -10, -10, -20},

    // Bishop
    {-20, -10, -10, -10, -10, -10, -10, -20,
     -10, 0, 0, 0, 0, 0, 0, -10,
     -10, 0, 5, 10, 10, 5, 0, -10,
     -10, 5, 5, 10, 10, 5, 5, -10,
     -10, 0, 10, 10, 10, 10, 0, -10,
     -10, 10, 10, 10, 10, 10, 10, -10,
     -10, 5, 0, 0, 0, 0, 5, -10,
     -20, -10, -10, -10, -10, -10, -10, -20},
    // Knight
    {-50, -40, -30, -30, -30, -30, -40, -50,
     -40, -20, 0, 0, 0, 0, -20, -40,
     -30, 0, 10, 15, 15, 10, 0, -30,
     -30, 5, 15, 20, 20, 15, 5, -30,
     -30, 0, 15, 20, 20, 15, 0, -30,
     -30, 5, 10, 15, 15, 10, 5, -30,
     -40, -20, 0, 5, 5, 0, -20, -40,
     -50, -40, -30, -30, -30, -30, -40, -50},
    // Rook
    {0, 0, 0, 0, 0, 0, 0, 0,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     -5, 0, 0, 0, 0, 0, 0, -5,
     0, 0, 0, 0, 0, 0, 0, 0},
    // Pawn
    {0, 0, 0, 0, 0, 0, 0, 0,
     80, 80, 80, 80, 80, 80, 80, 80,
     60, 60, 60, 60, 60, 60, 60, 60,
     40, 40, 40, 40, 40, 40, 40, 40,
     20, 20, 20, 20, 20, 20, 20, 20,
     0, 0, 0, 0, 0, 0, 0, 0,
     -20, -20, -20, -20, -20, -20, -20, -20,
     0, 0, 0, 0, 0, 0, 0, 0}};

enum PSMode
{
    Make = 1,
    Unmake = -1
};

inline float get_score_for_type(C_BoardState &board_state, float color, uint8_t piece_type, uint8_t target)
{
    uint8_t table_idx = board_state.phase * 6 + (piece_type - 1);
    uint8_t board_idx = color == White ? target : 63 - target;

    return PSTABLES[table_idx][board_idx];
}

inline float get_score(C_BoardState &board_state, float color, uint8_t at, uint8_t target)
{
    uint8_t piece_type = get_piece_type_of_field(board_state, at);
    return get_score_for_type(board_state, color, piece_type, target);
}

inline void update_score(PSMode mode, float &score, float &other_score, C_BoardState &board_state, move &move)
{
    score -= mode * get_score(board_state, board_state.turn, move.src, move.src);

    if (move.promotion)
    {
        score += mode * get_score_for_type(board_state, board_state.turn, move.promotion, move.dest);
    }
    else
    {
        score += mode * get_score(board_state, board_state.turn, move.src, move.dest);
    }

    if (move.capture)
    {
        uint8_t dest = move.ep ? move.dest - (int)board_state.turn : move.dest;
        other_score -= mode * get_score(board_state, -board_state.turn, dest, dest);
    }

    if (move.castling)
    {
        uint8_t rook_src = (move.castling == KingSide ? 7 : 0) + (board_state.turn == White ? 0 : 56);
        uint8_t rook_dest = (move.castling == KingSide ? 5 : 3) + (board_state.turn == White ? 0 : 56);
        score -= mode * get_score(board_state, board_state.turn, rook_src, rook_src);
        score += mode * get_score(board_state, board_state.turn, rook_src, rook_dest);
    }
}

#endif