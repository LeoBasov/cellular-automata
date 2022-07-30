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

TEST(game_of_life, CountNeighbourhood3) {
    const int x = 7;
    const int y = 13;
    RectGrid grid(x, y);

    grid.value(2, 4) = 1.0;
    grid.value(3, 5) = 1.0;
    grid.value(4, 3) = 1.0;

    ASSERT_EQ(3, CountNeighbourhood(grid, 3, 4));
}

TEST(game_of_life, CountNeighbourhood4) {
    const uint x = 7;
    const uint y = 13;
    RectGrid grid(x, y);

    grid.value(6, 0) = 1.0;
    grid.value(0, 12) = 1.0;
    grid.value(5, 12) = 1.0;
    grid.value(6, 11) = 1.0;

    ASSERT_EQ(4, CountNeighbourhood(grid, 6, 12));
}

TEST(game_of_life, Process_Block1) {
    const uint x = 4;
    const uint y = 4;
    Grid grid1(x, y);
    Grid grid2(x, y);

    grid1.value({1, 1}) = 1.0;
    grid1.value({2, 1}) = 1.0;
    grid1.value({1, 2}) = 1.0;
    grid1.value({2, 2}) = 1.0;

    for (uint i = 0; i < grid1.size(); i++) {
        Process(grid1, grid2, i);
    }

    for (uint i = 0; i < grid1.size(); i++) {
        ASSERT_DOUBLE_EQ(grid1.value(i), grid2.value(i));
    }
}

TEST(game_of_life, Process_Block2) {
    const uint x = 4;
    const uint y = 4;
    RectGrid grid1(x, y);
    RectGrid grid2(x, y);

    grid1.active_ = true;

    grid1.value(1, 1) = 1.0;
    grid1.value(2, 1) = 1.0;
    grid1.value(1, 2) = 1.0;
    grid1.value(2, 2) = 1.0;

    Process(grid1, grid2);

    for (size_t x = 0; x < grid1.size_x(); x++) {
        for (size_t y = 0; y < grid1.size_y(); y++) {
            ASSERT_DOUBLE_EQ(grid1.value(x, y), grid2.value(x, y));
        }
    }
}

TEST(game_of_life, Process_BeeHive) {
    const uint x = 6;
    const uint y = 5;
    Grid grid1(x, y);
    Grid grid2(x, y);

    grid1.value({1, 2}) = 1.0;
    grid1.value({4, 2}) = 1.0;

    grid1.value({2, 1}) = 1.0;
    grid1.value({3, 1}) = 1.0;

    grid1.value({2, 3}) = 1.0;
    grid1.value({3, 3}) = 1.0;

    for (uint i = 0; i < grid1.size(); i++) {
        Process(grid1, grid2, i);
    }

    for (uint i = 0; i < grid2.size(); i++) {
        ASSERT_DOUBLE_EQ(grid1.value(i), grid2.value(i));
    }
}

TEST(game_of_life, Process_Blinker1) {
    const uint x = 5;
    const uint y = 5;
    Grid grid1(x, y);
    Grid grid2(x, y);

    grid1.value({2, 3}) = 1.0;
    grid1.value({2, 2}) = 1.0;
    grid1.value({2, 1}) = 1.0;

    for (uint i = 0; i < grid1.size(); i++) {
        Process(grid1, grid2, i);
    }

    ASSERT_DOUBLE_EQ(1.0, grid2.value({1, 2}));
    ASSERT_DOUBLE_EQ(1.0, grid2.value({2, 2}));
    ASSERT_DOUBLE_EQ(1.0, grid2.value({3, 2}));
}

TEST(game_of_life, Process_Blinker2) {
    const uint x = 5;
    const uint y = 5;
    RectGrid grid1(x, y);
    RectGrid grid2(x, y);

    grid1.active_ = true;

    grid1.value(2, 3) = 1.0;
    grid1.value(2, 2) = 1.0;
    grid1.value(2, 1) = 1.0;

    Process(grid1, grid2);

    ASSERT_DOUBLE_EQ(1.0, grid2.value(1, 2));
    ASSERT_DOUBLE_EQ(1.0, grid2.value(2, 2));
    ASSERT_DOUBLE_EQ(1.0, grid2.value(3, 2));
}

TEST(game_of_life, Process_Glider) {
    const uint x = 6;
    const uint y = 6;
    Grid grid1(x, y);
    Grid grid2(x, y);

    grid1.value({1, 3}) = 1.0;
    grid1.value({2, 2}) = 1.0;
    grid1.value({3, 2}) = 1.0;
    grid1.value({3, 3}) = 1.0;
    grid1.value({3, 4}) = 1.0;

    for (uint i = 0; i < grid1.size(); i++) {
        Process(grid1, grid2, i);
    }

    ASSERT_DOUBLE_EQ(1.0, grid2.value({2, 2}));
    ASSERT_DOUBLE_EQ(1.0, grid2.value({2, 4}));

    ASSERT_DOUBLE_EQ(1.0, grid2.value({3, 2}));
    ASSERT_DOUBLE_EQ(1.0, grid2.value({3, 3}));

    ASSERT_DOUBLE_EQ(1.0, grid2.value({4, 3}));

    for (uint i = 0; i < grid2.size(); i++) {
        Process(grid2, grid1, i);
    }

    ASSERT_DOUBLE_EQ(1.0, grid1.value({2, 2}));

    ASSERT_DOUBLE_EQ(1.0, grid1.value({3, 2}));
    ASSERT_DOUBLE_EQ(1.0, grid1.value({3, 4}));

    ASSERT_DOUBLE_EQ(1.0, grid1.value({4, 2}));
    ASSERT_DOUBLE_EQ(1.0, grid1.value({4, 3}));
}

}  // namespace game_of_life
}  // namespace ca
