#ifndef BB_UTILS
#define BB_UTILS
#include <iostream>
#include <map>
#include <bit>
#include <array>
#include <list>
#include <stdint.h>
#include "bitboard_constants.hpp"

inline void print_move(move m)
{
    std::cout << "src: " << (int)m.src << "\n";
    std::cout << "dest:" << (int)m.dest << "\n";
    std::cout << "capt:" << (int)m.capture << "\n";
    std::cout << "flag:" << (int)m.flag << "\n\n";
}
enum pawn_shift
{
    single,
    attack_left,
    attack_right,
    single_reverse,
    attack_left_reverse,
    attack_right_reverse,
};

const std::map<pawn_shift, float>
    pawn_shift_map = {{single, 1.},
                      {attack_right, 9.},
                      {attack_left, -7.}};

const std::map<float, uint64_t>
    pawn_shift_mask_map = {
        {single, ~(row_8)},
        {attack_left, ~(row_8)},
        {attack_right, ~(row_8)}};

// shifts are denoted in field index change not left/right bit shift
// they are the negative of bit shift
inline uint64_t
shift_by_n(const float shift, const uint64_t val)
{
    return shift > 0 ? val >> (int)shift : val << (int)(shift * -1.);
}

// shifts are denoted in field index change not left/right bit shift
inline uint64_t mask_and_shift_by_n(const pawn_shift shift, uint64_t val, float color)
{
    uint64_t shift_mask = pawn_shift_mask_map.at(shift);
    return shift_by_n(pawn_shift_map.at(shift) * color, val & shift_mask);
}

inline std::array<uint8_t, 2> position_idx_to_col_row_idx(uint8_t position_idx)
{
    uint8_t col = (uint8_t)position_idx / 8;
    uint8_t row = position_idx % 8;
    return {col, row};
}

inline uint8_t col_row_idx_to_position_idx(uint8_t col_idx, uint8_t row_idx)
{
    return col_idx * 8 + row_idx;
}

inline int forward_scan(const uint64_t bb)
{
    uint64_t ls1b = bb & -bb; // isolate LS1B
    return std::__countl_zero(ls1b);
}

inline int reverse_scan(const uint64_t bb)
{
    return std::__countl_zero(bb);
}

inline bool get_board_at_idx(uint64_t bb, int idx)
{
    return (bool)(bb & (most_sig_bit >> idx));
}

inline uint64_t set_board_1_at_idx(uint64_t bb, int idx)
{
    return bb | (most_sig_bit >> idx);
}

inline uint64_t set_board_0_at_idx(uint64_t bb, int idx)
{
    return bb & ~(most_sig_bit >> idx);
}

inline uint64_t board_from_idx_list(std::list<int> idx_list)
{
    uint64_t bb = empty_board;
    for (int idx : idx_list)
    {
        set_board_1_at_idx(bb, idx);
    }
    return bb;
}

inline std::vector<int> scan_board(uint64_t bb)
{
    std::vector<int> idx_list = std::vector<int>();
    if (bb)
    {
        idx_list.reserve(16);
        do
        {
            idx_list.push_back(forward_scan(bb));
        } while (bb &= bb - 1);
    }
    return idx_list;
}

inline std::vector<int> scan_board_reverse(uint64_t bb)
{
    std::vector<int> idx_list = std::vector<int>();
    if (bb)
    {
        idx_list.reserve(16);
        int reverse_scan_idx = 0;
        do
        {
            reverse_scan_idx = reverse_scan(bb);
            idx_list.push_back(reverse_scan_idx);
        } while (bb &= ~(most_sig_bit >> reverse_scan_idx));
    }

    return idx_list;
}

inline std::string field_id_to_string(uint8_t idx)
{
    std::array<uint8_t, 2> col_row = position_idx_to_col_row_idx(idx);
    return col_int_to_string_map.at(col_row[0]) + std::to_string(col_row[1] + 1);
}

inline std::string move_to_uci_str(const move m)
{
    if (m.flag != 0)
    {
        return field_id_to_string(m.src) + field_id_to_string(m.dest) + piece_code_to_char.at(m.flag);
    }
    else
    {
        return field_id_to_string(m.src) + field_id_to_string(m.dest);
    }
}

#endif