#ifndef TEST_UTILS
#define TEST_UTILS

#include <string>
#include <iostream>
#include <stdint.h>
#include "../include/constants.hpp"
#include "../include/types.hpp"
#include "../include/transforms.hpp"

inline void print_bitboard(uint64_t bb)
{
    std::string bb_str = "";
    for (int row = 0; row < 8; row++)
    {
        for (int col = 7; col >= 0; col--)
        {
            uint64_t index = 1;
            std::string bit = bb & (index << (col * 8 + row)) ? "1" : "∙";
            bb_str += bit;
            if (col != 0)
            {
                bb_str += " ";
            }
        }
        bb_str += '\n';
    }
    bb_str += '\n';
    std::cout << bb_str;
}

inline Board get_example_board()
{
    Board board = Board();
    board[0] = {5, 6, 0, 0, 0, 0, -6, -5};
    board[1] = {4, 6, 0, 0, 0, 0, -6, -4};
    board[2] = {3, 6, 0, 0, 0, 0, -6, -3};
    board[3] = {2, 6, 0, 0, 0, 0, -6, -2};
    board[4] = {1, 6, 0, 0, 0, 0, -6, -1};
    board[5] = {3, 6, 0, 0, 0, 0, -6, -3};
    board[6] = {4, 6, 0, 0, 0, 0, -6, -4};
    board[7] = {5, 6, 0, 0, 0, 0, -6, -5};
    return board;
}

inline C_BoardState get_new_game_board()
{
    C_BoardState board;
    uint64_t black_pieces = black_king_starting_config | black_queen_starting_config | black_bishops_starting_config | black_knights_starting_config | black_rooks_starting_config | black_pawns_starting_config;
    uint64_t white_pieces = white_king_starting_config | white_queen_starting_config | white_bishops_starting_config | white_knights_starting_config | white_rooks_starting_config | white_pawns_starting_config;

    board.pieces[b_black] = black_pieces;
    board.pieces[b_white] = white_pieces;

    board.pieces[b_kings] = black_king_starting_config | white_king_starting_config;
    board.pieces[b_queens] = black_queen_starting_config | white_queen_starting_config;
    board.pieces[b_bishops] = black_bishops_starting_config | white_bishops_starting_config;
    board.pieces[b_knights] = black_knights_starting_config | white_knights_starting_config;
    board.pieces[b_rooks] = black_rooks_starting_config | white_rooks_starting_config;
    board.pieces[b_pawns] = black_pawns_starting_config | white_pawns_starting_config;

    return board;
}

int flat(int row, int col);

uint64_t fill_bitboard(std::vector<std::pair<int, int>> positions);

uint64_t fill_bitboard_max(uint64_t bitboard, std::vector<int> positions);

template <class T>
inline bool exists(std::vector<T> iterable, std::function<bool(T)> condition)
{
    bool found;
    for (auto item : iterable)
    {
        found = found || condition(item);
    }
    return found;
}

inline C_BoardState init_board_state_for_test(float turn = White)
{
    C_BoardState board_state{.turn = turn};
    set_pieces(board_state, White, pKing, fill_bitboard({{4, 0}}));
    set_pieces(board_state, Black, pKing, fill_bitboard({{4, 7}}));
    return board_state;
}
#endif