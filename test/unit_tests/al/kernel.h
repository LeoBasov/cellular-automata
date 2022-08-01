#pragma once

#include <gtest/gtest.h>

#include "../../../src/al/kernel.h"

namespace ca {
namespace kernel {

TEST(kernel, Rectangular) {
    const uint x = 3;
    const uint y = 3;
    const uint x_centre = 1;
    const uint y_centre = 1;
    Grid grid(x, y);
    double value = 0.0;
    double tot_value = 0.0;
    double count = 0.0;

    for (size_t i = 0; i < grid.size_x(); i++) {
        for (size_t j = 0; j < grid.size_y(); j++) {
            tot_value += value;
            grid.value(i, j) = value;
            value += 1.0;
        }
    }

    count += grid.value(x_centre - 1, y_centre - 1) * Rectangular(1.0, 1.0, 0.0, 0.75);
    count += grid.value(x_centre - 1, y_centre + 0) * Rectangular(1.0, 0.0, 0.0, 0.75);
    count += grid.value(x_centre - 1, y_centre + 1) * Rectangular(1.0, 1.0, 0.0, 0.75);

    count += grid.value(x_centre - 0, y_centre - 1) * Rectangular(0.0, 1.0, 0.0, 0.75);
    count += grid.value(x_centre - 0, y_centre + 0) * Rectangular(0.0, 0.0, 0.0, 0.75);
    count += grid.value(x_centre - 0, y_centre + 1) * Rectangular(0.0, 1.0, 0.0, 0.75);

    count += grid.value(x_centre + 1, y_centre - 1) * Rectangular(0.0, 1.0, 0.0, 0.75);
    count += grid.value(x_centre + 1, y_centre + 0) * Rectangular(0.0, 0.0, 0.0, 0.75);
    count += grid.value(x_centre + 1, y_centre + 1) * Rectangular(0.0, 1.0, 0.0, 0.75);

    ASSERT_DOUBLE_EQ(tot_value, count);
}

TEST(kernel, Moore) {
    const uint x = 9;
    const uint y = 9;
    const uint x_centre = 4;
    const uint y_centre = 4;
    Grid grid(x, y);

    for (size_t i = 0; i < grid.size_x(); i++) {
        for (size_t j = 0; j < grid.size_y(); j++) {
            grid.value(i, j) = 1.0;
        }
    }

    const double count = Kernel(grid, x_centre, y_centre, MOORE);

    ASSERT_DOUBLE_EQ(9.0, count);
}

TEST(kernel, Full) {
    const uint x = 9;
    const uint y = 9;
    const uint x_centre = 4;
    const uint y_centre = 4;
    Grid grid(x, y);

    for (size_t i = 0; i < grid.size_x(); i++) {
        for (size_t j = 0; j < grid.size_y(); j++) {
            grid.value(i, j) = 1.0;
        }
    }

    const double count = Kernel(grid, x_centre, y_centre, FULL);

    ASSERT_DOUBLE_EQ(5.0 * 5.0 + 4.0 * 3.0, count);
}

}  // namespace kernel
}  // namespace ca
