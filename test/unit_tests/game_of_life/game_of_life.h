#pragma once

#include <gtest/gtest.h>

#include "../../../src/al/game_of_life.h"

namespace ca {
namespace game_of_life {

TEST(game_of_life, CountNeighbourhood1) {
    const uint x = 7;
    const uint y = 13;
    Grid grid(x, y);
    Pair coords = {3, 4};

    grid.value({2, 4}) = 1.0;
    grid.value({3, 5}) = 1.0;
    grid.value({4, 3}) = 1.0;

    ASSERT_EQ(3, CountNeighbourhood(grid, coords));
}

TEST(game_of_life, CountNeighbourhood2) {
    const uint x = 7;
    const uint y = 13;
    Grid grid(x, y);
    Pair coords = {6, 12};

    grid.value({6, 0}) = 1.0;
    grid.value({0, 12}) = 1.0;
    grid.value({5, 12}) = 1.0;
    grid.value({6, 11}) = 1.0;

    ASSERT_EQ(4, CountNeighbourhood(grid, coords));
}

}  // namespace game_of_life
}  // namespace ca
