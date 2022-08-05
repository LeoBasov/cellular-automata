#pragma once

#include <gtest/gtest.h>

#include "../../../src/grid/fast_grid.h"

namespace ca {

TEST(FastGrid, Constructor) {
    const uint x1 = 3;
    const uint x2 = 7;
    const uint x3 = 11;
    const uint y1 = 13;
    const uint y2 = 17;
    const uint y3 = 23;
    const FastGrid grid = FastGrid();
    const FastGrid grid1 = FastGrid(x1, y1);
    const FastGrid grid2 = FastGrid(x2, y2);
    const FastGrid grid3 = FastGrid(x3, y3);

    ASSERT_EQ(1, grid.x_);
    ASSERT_EQ(3, grid1.x_);
    ASSERT_EQ(7, grid2.x_);
    ASSERT_EQ(11, grid3.x_);

    ASSERT_EQ(1, grid.y_);
    ASSERT_EQ(13, grid1.y_);
    ASSERT_EQ(17, grid2.y_);
    ASSERT_EQ(23, grid3.y_);

    for (int x = 0; x < grid.x_; x++) {
        for (int y = 0; y < grid.y_; y++) {
            ASSERT_EQ(0.0, grid.value(x, y));
        }
    }

    for (int x = 0; x < grid1.x_; x++) {
        for (int y = 0; y < grid1.y_; y++) {
            ASSERT_EQ(0.0, grid1.value(x, y));
        }
    }
}

TEST(FastGrid, value) {
    const uint x = 5;
    const uint y = 6;
    FastGrid grid(x, y);

    grid.value(0, 0) = 1.0;
    grid.value(4, 0) = 2.0;

    grid.value(0, 5) = 3.0;
    grid.value(4, 5) = 4.0;

    ASSERT_EQ(1.0, grid.value(0, 0));
    ASSERT_EQ(1.0, grid.value(5, 0));
    ASSERT_EQ(1.0, grid.value(0, 6));

    ASSERT_EQ(2.0, grid.value(4, 0));
    ASSERT_EQ(2.0, grid.value(-1, 0));
    ASSERT_EQ(2.0, grid.value(4, 6));

    ASSERT_EQ(3.0, grid.value(0, 5));
    ASSERT_EQ(3.0, grid.value(5, 5));
    ASSERT_EQ(3.0, grid.value(0, -1));

    ASSERT_EQ(4.0, grid.value(4, 5));
    ASSERT_EQ(4.0, grid.value(-1, 5));
    ASSERT_EQ(4.0, grid.value(4, -1));
}

}  // namespace ca
