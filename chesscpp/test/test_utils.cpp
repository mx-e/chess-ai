#include "test_utils.hpp"

uint64_t fill_bitboard(std::vector<std::pair<int, int>> positions)
{
    uint64_t bitboard = 0;
    for (auto position : positions)
    {
        uint8_t idx = flat(position.first, position.second);
        bitboard |= (most_sig_bit >> idx);
    }
    return bitboard;
}

int flat(int row, int col)
{
    return row * 8 + col;
}

