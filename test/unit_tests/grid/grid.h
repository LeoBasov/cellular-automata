#pragma once

#include <gtest/gtest.h>

#include "../../../src/grid/grid.h"

namespace ca {

TEST(Grid, Constructor) {
    const uint x1 = 3;
    const uint x2 = 7;
    const uint x3 = 11;
    const uint y1 = 13;
    const uint y2 = 17;
    const uint y3 = 23;
    const Grid grid = Grid();
    const Grid grid1 = Grid(x1, y1);
    const Grid grid2 = Grid(x2, y2);
    const Grid grid3 = Grid(x3, y3);

    ASSERT_EQ(1, grid.x());
    ASSERT_EQ(3, grid1.x());
    ASSERT_EQ(7, grid2.x());
    ASSERT_EQ(11, grid3.x());

    ASSERT_EQ(1, grid.y());
    ASSERT_EQ(13, grid1.y());
    ASSERT_EQ(17, grid2.y());
    ASSERT_EQ(23, grid3.y());

    ASSERT_EQ(1, grid.values().size());
    ASSERT_EQ(x1 * y1, grid1.values().size());
    ASSERT_EQ(x2 * y2, grid2.values().size());
    ASSERT_EQ(x3 * y3, grid3.values().size());

    for (const auto& elem : grid.values()) {
        ASSERT_DOUBLE_EQ(0.0, elem);
    }

    for (const auto& elem : grid1.values()) {
        ASSERT_DOUBLE_EQ(0.0, elem);
    }

    for (const auto& elem : grid2.values()) {
        ASSERT_DOUBLE_EQ(0.0, elem);
    }

    for (const auto& elem : grid3.values()) {
        ASSERT_DOUBLE_EQ(0.0, elem);
    }
}

TEST(Grid, coords) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    const uint idx1 = 0;
    const uint idx2 = 6;
    const uint idx3 = 7;
    const uint idx4 = 12;
    const uint idx5 = 17;

    const Pair res1 = grid.coords(idx1);
    const Pair res2 = grid.coords(idx2);
    const Pair res3 = grid.coords(idx3);
    const Pair res4 = grid.coords(idx4);
    const Pair res5 = grid.coords(idx5);

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

TEST(Grid, idx) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    const Pair coords1 = {0, 0};
    const Pair coords2 = {5, 3};
    const Pair coords3 = {6, 12};
    const Pair coords4 = {7, 13};

    ASSERT_EQ(0, grid.idx(coords1));
    ASSERT_EQ(3 * x + 5, grid.idx(coords2));
    ASSERT_EQ(12 * x + 6, grid.idx(coords3));

    EXPECT_THROW(grid.idx(coords4), Exception);
}

TEST(Grid, CoordXPlus_Coords) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {5, 3};
    Pair coords2 = {6, 12};

    grid.CoordXPlus(coords1);
    grid.CoordXPlus(coords2);

    ASSERT_EQ(6, coords1.first);
    ASSERT_EQ(3, coords1.second);

    ASSERT_EQ(0, coords2.first);
    ASSERT_EQ(12, coords2.second);
}

TEST(Grid, CoordXPlus_Idx) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {5, 3};
    Pair coords2 = {6, 12};
    const uint idx1 = grid.idx(coords1);
    const uint idx2 = grid.idx(coords2);

    const uint idx1_new = grid.CoordXPlus(idx1);
    const uint idx2_new = grid.CoordXPlus(idx2);

    grid.CoordXPlus(coords1);
    grid.CoordXPlus(coords2);

    ASSERT_EQ(grid.idx(coords1), idx1_new);
    ASSERT_EQ(grid.idx(coords2), idx2_new);
}

TEST(Grid, CoordXMinus_Coords) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {0, 3};
    Pair coords2 = {6, 12};

    grid.CoordXMinus(coords1);
    grid.CoordXMinus(coords2);

    ASSERT_EQ(6, coords1.first);
    ASSERT_EQ(3, coords1.second);

    ASSERT_EQ(5, coords2.first);
    ASSERT_EQ(12, coords2.second);
}

TEST(Grid, CoordXMinus_Idx) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {0, 3};
    Pair coords2 = {6, 12};
    const uint idx1 = grid.idx(coords1);
    const uint idx2 = grid.idx(coords2);

    const uint idx1_new = grid.CoordXMinus(idx1);
    const uint idx2_new = grid.CoordXMinus(idx2);

    grid.CoordXMinus(coords1);
    grid.CoordXMinus(coords2);

    ASSERT_EQ(grid.idx(coords1), idx1_new);
    ASSERT_EQ(grid.idx(coords2), idx2_new);
}

TEST(Grid, CoordYPlus_Coords) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {5, 3};
    Pair coords2 = {6, 12};

    grid.CoordYPlus(coords1);
    grid.CoordYPlus(coords2);

    ASSERT_EQ(5, coords1.first);
    ASSERT_EQ(4, coords1.second);

    ASSERT_EQ(6, coords2.first);
    ASSERT_EQ(0, coords2.second);
}

TEST(Grid, CoordYPlus_Idx) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {5, 3};
    Pair coords2 = {6, 12};
    const uint idx1 = grid.idx(coords1);
    const uint idx2 = grid.idx(coords2);

    const uint idx1_new = grid.CoordYPlus(idx1);
    const uint idx2_new = grid.CoordYPlus(idx2);

    grid.CoordYPlus(coords1);
    grid.CoordYPlus(coords2);

    ASSERT_EQ(grid.idx(coords1), idx1_new);
    ASSERT_EQ(grid.idx(coords2), idx2_new);
}

TEST(Grid, CoordYMinus_Coords) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {0, 0};
    Pair coords2 = {6, 12};

    grid.CoordYMinus(coords1);
    grid.CoordYMinus(coords2);

    ASSERT_EQ(0, coords1.first);
    ASSERT_EQ(12, coords1.second);

    ASSERT_EQ(6, coords2.first);
    ASSERT_EQ(11, coords2.second);
}

TEST(Grid, CoordYMinus_Idx) {
    const uint x = 7;
    const uint y = 13;
    const Grid grid = Grid(x, y);
    Pair coords1 = {0, 0};
    Pair coords2 = {6, 12};
    const uint idx1 = grid.idx(coords1);
    const uint idx2 = grid.idx(coords2);

    const uint idx1_new = grid.CoordYMinus(idx1);
    const uint idx2_new = grid.CoordYMinus(idx2);

    grid.CoordYMinus(coords1);
    grid.CoordYMinus(coords2);

    ASSERT_EQ(grid.idx(coords1), idx1_new);
    ASSERT_EQ(grid.idx(coords2), idx2_new);
}

}  // namespace ca
