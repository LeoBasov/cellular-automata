#pragma once

#include <gtest/gtest.h>

#include "../../../src/grid/rect_grid.h"

namespace ca {

TEST(RectGrid, Constructor) {
    const uint x1 = 3;
    const uint x2 = 7;
    const uint x3 = 11;
    const uint y1 = 13;
    const uint y2 = 17;
    const uint y3 = 23;
    const RectGrid grid = RectGrid();
    const RectGrid grid1 = RectGrid(x1, y1);
    const RectGrid grid2 = RectGrid(x2, y2);
    const RectGrid grid3 = RectGrid(x3, y3);

    ASSERT_EQ(1, grid.size_x());
    ASSERT_EQ(3, grid1.size_x());
    ASSERT_EQ(7, grid2.size_x());
    ASSERT_EQ(11, grid3.size_x());

    ASSERT_EQ(1, grid.size_y());
    ASSERT_EQ(13, grid1.size_y());
    ASSERT_EQ(17, grid2.size_y());
    ASSERT_EQ(23, grid3.size_y());

    for (size_t x = 0; x < grid.size_x(); x++) {
        for (size_t y = 0; y < grid.size_y(); y++) {
            ASSERT_EQ(0.0, grid.value(x, y));
        }
    }
}

}  // namespace ca
