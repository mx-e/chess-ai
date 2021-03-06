#ifndef PSTABLES_H
#define PSTABLES_H

#include <array>
#include <vector>
#include <map>
#include "utils.hpp"
#include "evaluation_constants.hpp"

// Source: https://github.com/GunshipPenguin/shallow-blue/blob/master/src/psquaretable.cc
const std::map<float, int> color_to_pstable_idx = {{1., 0}, {-1, 1}};

// 
const float PSTABLES[2][2][6][64] = {
    // White
    {{// King
      {
       30, 20, -10, -20, -30, -30, -30, -30,
       30, 20, -20, -30, -40, -40, -40, -40,
       20, 0, -20, -30, -40, -40, -40, -40,
       20, 0, -20, 100, 100, -50, -50, -50,
       20, 0, -20, 100, 100, -50, -50, -50,
       30, 0, -20, -30, -40, -40, -40, -40,
       30, 20, -20, -30, -40, -40, -40, -40,
       30, 20, -10, -20, -30, -30, -30, -30},
      // Queen
      {-20, -10, -10, 0, -5, -10, -10, -20,
       -10, 0, 5, 0, 0, 0, 0, -10,
       -10, 5, 5, 5, 5, 5, 0, -10,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -10, 0, 5, 5, 5, 5, 0, -10,
       -10, 0, 0, 0, 0, 0, 0, -10,
       -20, -10, -10, -5, -5, -10, -10, -20},
      // Bishop
      {-20, -10, -10, -10, -10, -10, -10, -20,
       -10, 5, 10, 0, 5, 0, 0, -10,
       -10, 0, 10, 10, 5, 5, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 10, 10, 5, 5, 0, -10,
       -10, 5, 10, 0, 5, 0, 0, -10,
       -20, -10, -10, -10, -10, -10, -10, -20},
      // Knight
      {-50, -40, -30, -30, -30, -30, -40, -50,
       -40, -20, 5, 0, 5, 0, -20, -40,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -30, 5, 15, 20, 20, 15, 0, -30,
       -30, 5, 15, 20, 20, 15, 0, -30,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -40, -20, 5, 0, 5, 0, -20, -40,
       -50, -40, -30, -30, -30, -30, -40, -50},
      // Rook
      {0, -5, -5, -5, -5, -5, 5, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       5, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       5, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, -5, -5, -5, -5, -5, 5, 0},
      // Pawn
      {0, 5, 5, 0, 5, 10, 50, 0,
       0, 10, -5, 0, 5, 10, 50, 0,
       0, 10, -10, 0, 10, 20, 50, 0,
       0, -20, 0, 20, 25, 30, 50, 0,
       0, -20, 0, 20, 25, 30, 50, 0,
       0, 10, -10, 0, 10, 20, 50, 0,
       0, 10, -5, 0, 5, 10, 50, 0,
       0, 5, 5, 0, 5, 10, 50, 0}},
     {// King
      {-50, -30, -30, -30, -30, -30, -30, -50,
       -30, -30, -10, -10, -10, -10, -20, -40,
       -30, 0, 20, 30, 30, 20, -10, -30,
       -30, 0, 30, 200, 200, 30, 0, -20,
       -30, 0, 30, 200, 200, 30, 0, -20,
       -30, 0, 20, 30, 30, 20, -10, -30,
       -30, -30, -10, -10, -10, -10, -20, -40,
       -50, -30, -30, -30, -30, -30, -30, -50},
      // Queen
      {-20, -10, -10, 0, -5, -10, -10, -20,
       -10, 0, 5, 0, 0, 0, 0, -10,
       -10, 5, 5, 5, 5, 5, 0, -10,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -10, 0, 5, 5, 5, 5, 0, -10,
       -10, 0, 0, 0, 0, 0, 0, -10,
       -20, -10, -10, -5, -5, -10, -10, -20},
      // Bishop
      {-20, -10, -10, -10, -10, -10, -10, -20,
       -10, 5, 10, 0, 5, 0, 0, -10,
       -10, 0, 10, 10, 5, 5, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 10, 10, 5, 5, 0, -10,
       -10, 5, 10, 0, 5, 0, 0, -10,
       -20, -10, -10, -10, -10, -10, -10, -20},
      // Knight
      {-50, -40, -30, -30, -30, -30, -40, -50,
       -40, -20, 5, 0, 5, 0, -20, -40,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -30, 5, 15, 20, 20, 15, 0, -30,
       -30, 5, 15, 20, 20, 15, 0, -30,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -40, -20, 5, 0, 5, 0, -20, -40,
       -50, -40, -30, -30, -30, -30, -40, -50},
      // Rook
      {0, -5, -5, -5, -5, -5, -5, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, -5, -5, -5, -5, -5, -5, 0},
      // Pawn
      {0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0,
       0, -20, 0, 20, 40, 60, 80, 0}}},
    // Black
    {{// King
      {-30, -30, -30, -30, -20, -10, 20, 30,
       -40, -40, -40, -40, -30, -20, 20, 30,
       -40, -40, -40, -40, -30, -20, 0, 20,
       -50, -50, -50, 100, 100, -20, 0, 20,
       -50, -50, -50, 100, 100, -20, 0, 20,
       -40, -40, -40, -40, -30, -20, 0, 30,
       -40, -40, -40, -40, -30, -20, 20, 30,
       -30, -30, -30, -30, -20, -10, 20, 30},
      // Queen
      {-20, -10, -10, -5, 0, -10, -10, -20,
       -10, 0, 0, 0, 0, 5, 0, -10,
       -10, 0, 5, 5, 5, 5, 5, -10,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -10, 0, 5, 5, 5, 5, 0, -10,
       -10, 0, 0, 0, 0, 0, 0, -10,
       -20, -10, -10, -5, -5, -10, -10, -20},
      // Bishop
      {-20, -10, -10, -10, -10, -10, -10, -20,
       -10, 0, 0, 5, 0, 10, 5, -10,
       -10, 0, 5, 5, 10, 10, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 5, 5, 10, 10, 0, -10,
       -10, 0, 0, 5, 0, 10, 5, -10,
       -20, -10, -10, -10, -10, -10, -10, -20},
      // Knight
      {-50, -40, -30, -30, -30, -30, -40, -50,
       -40, -20, 0, 5, 0, 5, -20, -40,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -30, 0, 15, 20, 20, 15, 5, -30,
       -30, 0, 15, 20, 20, 15, 5, -30,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -40, -20, 0, 5, 0, 5, -20, -40,
       -50, -40, -30, -30, -30, -30, -40, -50},
      // Rook
      {0, 5, -5, -5, -5, -5, -5, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 5,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 5,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 5, -5, -5, -5, -5, -5, 0},
      // Pawn
      {0, 50, 10, 5, 0, 5, 5, 0,
       0, 50, 10, 5, 0, -5, 10, 0,
       0, 50, 20, 10, 0, -10, 10, 0,
       0, 50, 30, 25, 20, 0, -20, 0,
       0, 50, 30, 25, 20, 0, -20, 0,
       0, 50, 20, 10, 0, -10, 10, 0,
       0, 50, 10, 5, 0, -5, 10, 0,
       0, 50, 10, 5, 0, 5, 5, 0}},
     {// King
      {-50, -30, -30, -30, -30, -30, -30, -50,
       -40, -20, -10, -10, -10, -10, -30, -30,
       -30, -10, 20, 30, 30, 20, 0, -30,
       -20, 0, 30, 200, 200, 30, 0, -30,
       -20, 0, 30, 200, 200, 30, 0, -30,
       -30, -10, 20, 30, 30, 20, 0, -30,
       -40, -20, -10, -10, -10, -10, -30, -30,
       -50, -30, -30, -30, -30, -30, -30, -50},
      // Queen
      {-20, -10, -10, -5, 0, -10, -10, -20,
       -10, 0, 0, 0, 0, 5, 0, -10,
       -10, 0, 5, 5, 5, 5, 5, -10,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -5, 0, 5, 5, 5, 5, 0, -5,
       -10, 0, 5, 5, 5, 5, 0, -10,
       -10, 0, 0, 0, 0, 0, 0, -10,
       -20, -10, -10, -5, -5, -10, -10, -20},
      // Bishop
      {-20, -10, -10, -10, -10, -10, -10, -20,
       -10, 0, 0, 5, 0, 10, 5, -10,
       -10, 0, 5, 5, 10, 10, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 10, 10, 10, 10, 0, -10,
       -10, 0, 5, 5, 10, 10, 0, -10,
       -10, 0, 0, 5, 0, 10, 5, -10,
       -20, -10, -10, -10, -10, -10, -10, -20},
      // Knight
      {-50, -40, -30, -30, -30, -30, -40, -50,
       -40, -20, 0, 5, 0, 5, -20, -40,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -30, 0, 15, 20, 20, 15, 5, -30,
       -30, 0, 15, 20, 20, 15, 5, -30,
       -30, 0, 10, 15, 15, 10, 0, -30,
       -40, -20, 0, 5, 0, 5, -20, -40,
       -50, -40, -30, -30, -30, -30, -40, -50},
      // Rook
      {0, -5, -5, -5, -5, -5, -5, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, -5, -5, -5, -5, -5, -5, 0},
      // Pawn
      {0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0,
       0, 80, 60, 40, 20, 0, -20, 0}}}};

enum PSMode
{
    Make = 1,
    Unmake = -1
};

inline float get_score_for_type(Phase phase, float color, uint8_t piece_type, uint8_t target)
{
    return PSTABLES[color_to_pstable_idx.at(color)][phase][piece_type - 1][target];
}

inline float get_score(C_BoardState &board_state, Phase phase, float color, uint8_t at, uint8_t target)
{
    uint8_t piece_type = get_piece_type_of_field(board_state, at);
    return get_score_for_type(phase, color, piece_type, target);
}

inline void update_score(PSMode mode, Phase phase, float &score, float &other_score, C_BoardState &board_state, move &move)
{
    score -= mode * get_score(board_state, phase, board_state.turn, move.src, move.src);

    if (move.promotion)
    {
        score += mode * get_score_for_type(phase, board_state.turn, move.promotion, move.dest);
    }
    else
    {
        score += mode * get_score(board_state, phase, board_state.turn, move.src, move.dest);
    }

    if (move.capture || move.ep)
    {
        uint8_t dest = move.ep ? move.dest - (int)board_state.turn : move.dest;
        other_score -= mode * get_score(board_state, phase, -board_state.turn, dest, dest);
    }

    if (move.castling)
    {
        uint8_t rook_src = 8 * (move.castling == KingSide ? 7 : 0) + (board_state.turn == White ? 0 : 7);
        uint8_t rook_dest = 8 * (move.castling == KingSide ? 5 : 3) + (board_state.turn == White ? 0 : 7);
        score -= mode * get_score(board_state, phase, board_state.turn, rook_src, rook_src);
        score += mode * get_score(board_state, phase, board_state.turn, rook_src, rook_dest);
    }
}

#endif