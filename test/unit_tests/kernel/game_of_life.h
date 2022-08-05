#pragma once

#include <gtest/gtest.h>

#include "../../../src/grid/grid.h"
#include "../../../src/kernel/game_of_life.h"

namespace ca {

TEST(GameOfLife, Full) {
    const int x = 9;
    const int y = 9;
    const int x_centre = 4;
    const int y_centre = 4;
    const int radius = 1;
    GameOfLife kernel;
    Grid grid(x, y);
    double count = 0.0;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            grid.value(i, j) = 1.0;
            ;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            count += grid.value(i, j) * kernel.Value(-x_centre + i, -y_centre + j);
        }
    }

    ASSERT_DOUBLE_EQ(1.0, kernel.Convolute(grid, x_centre, y_centre, radius));
}

TEST(GameOfLife, GameOfLife_BeeHive) {
    const uint x = 6;
    const uint y = 5;
    const uint x_centre = 0;
    const uint y_centre = 1;
    const uint radius = 1;
    Grid grid(x, y);
    GameOfLife kernel;
    double count = 0.0;

    grid.value(1, 2) = 1.0;
    grid.value(4, 2) = 1.0;

    grid.value(2, 1) = 1.0;
    grid.value(3, 1) = 1.0;

    grid.value(2, 3) = 1.0;
    grid.value(3, 3) = 1.0;

    ASSERT_DOUBLE_EQ(1.0 / 8.5, kernel.Convolute(grid, x_centre, y_centre, radius));
}

}  // namespace ca
