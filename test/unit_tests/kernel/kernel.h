#pragma once

#include <gtest/gtest.h>

#include "../../../src/kernel/kernel.h"

namespace ca {

TEST(Kernel, Full) {
    const int x = 5;
    const int y = 5;
    Kernel kernel;
    Grid grid(x, y);

    kernel.SetUpGameOfLife(grid);

    for (int x__ = 1; x__ < 4; x__++) {
        for (int y__ = 1; y__ < 4; y__++) {
            grid.value(x__, y__) = 1.0;
        }
    }

    grid.grid_ = kernel.kernel_ * grid.grid_;

    ASSERT_DOUBLE_EQ(1.0 / 8.5, grid.value(0, 0));
    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(1, 0));
    ASSERT_DOUBLE_EQ(3.0 / 8.5, grid.value(2, 0));
    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(3, 0));
    ASSERT_DOUBLE_EQ(1.0 / 8.5, grid.value(4, 0));

    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(0, 1));
    ASSERT_DOUBLE_EQ(3.5 / 8.5, grid.value(1, 1));
    ASSERT_DOUBLE_EQ(5.5 / 8.5, grid.value(2, 1));
    ASSERT_DOUBLE_EQ(3.5 / 8.5, grid.value(3, 1));
    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(4, 1));

    ASSERT_DOUBLE_EQ(3.0 / 8.5, grid.value(0, 2));
    ASSERT_DOUBLE_EQ(5.5 / 8.5, grid.value(1, 2));
    ASSERT_DOUBLE_EQ(8.5 / 8.5, grid.value(2, 2));
    ASSERT_DOUBLE_EQ(5.5 / 8.5, grid.value(3, 2));
    ASSERT_DOUBLE_EQ(3.0 / 8.5, grid.value(4, 2));

    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(0, 3));
    ASSERT_DOUBLE_EQ(3.5 / 8.5, grid.value(1, 3));
    ASSERT_DOUBLE_EQ(5.5 / 8.5, grid.value(2, 3));
    ASSERT_DOUBLE_EQ(3.5 / 8.5, grid.value(3, 3));
    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(4, 3));

    ASSERT_DOUBLE_EQ(1.0 / 8.5, grid.value(0, 4));
    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(1, 4));
    ASSERT_DOUBLE_EQ(3.0 / 8.5, grid.value(2, 4));
    ASSERT_DOUBLE_EQ(2.0 / 8.5, grid.value(3, 4));
    ASSERT_DOUBLE_EQ(1.0 / 8.5, grid.value(4, 4));
}

}  // namespace ca
