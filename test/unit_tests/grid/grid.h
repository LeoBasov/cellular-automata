#pragma once

#include <gtest/gtest.h>

#include "../../../src/grid/grid.h"

namespace ca {

TEST(Grid, Coords) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    const uint idx1 = 0;
    const uint idx2 = 6;
    const uint idx3 = 7;
    const uint idx4 = 12;
    const uint idx5 = 17;

    const Pair res1 = grid.Coords(idx1);
    const Pair res2 = grid.Coords(idx2);
    const Pair res3 = grid.Coords(idx3);
    const Pair res4 = grid.Coords(idx4);
    const Pair res5 = grid.Coords(idx5);

    ASSERT_EQ(0, res1.first);
    ASSERT_EQ(6, res2.first);
    ASSERT_EQ(0, res3.first);
    ASSERT_EQ(5, res4.first);
    ASSERT_EQ(3, res5.first);

    ASSERT_EQ(0, res1.second);
    ASSERT_EQ(0, res2.second);
    ASSERT_EQ(1, res3.second);
    ASSERT_EQ(1, res4.second);
    ASSERT_EQ(2, res5.second);
}

}  // namespace ca
