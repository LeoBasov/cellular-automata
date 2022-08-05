#pragma once

#include <gtest/gtest.h>

#include "../../../src/kernel/rectangular.h"

namespace ca {

TEST(Rectangular, SetUp_1) {
    const double min = 0.0;
    const double max = std::sqrt(2.0);
    Rectangular kernel;

    kernel.SetUp(min, max);

    ASSERT_DOUBLE_EQ(1.0 / 9.0, kernel.GetNorm());
}

TEST(Rectangular, SetUp_2) {
    const double min = 0.0;
    const double max = 0.25;
    Rectangular kernel;

    kernel.SetUp(min, max);

    ASSERT_DOUBLE_EQ(1.0, kernel.GetNorm());
}

TEST(Rectangular, Value) {
    const double min1 = 0.0;
    const double max1 = 0.25;
    const double min2 = 0.25;
    const double max2 = std::sqrt(2.0);
    Rectangular kernel1;
    Rectangular kernel2;

    kernel1.SetUp(min1, max1);
    kernel2.SetUp(min2, max2);

    // kernel inner

    ASSERT_DOUBLE_EQ(1.0, kernel1.Value(0.0, 0.0));

    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(1.0, 0.0));
    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(1.0, 1.0));
    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(0.0, 1.0));
    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(-1.0, 1.0));

    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(0.0, -1.0));
    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(-1.0, 0.0));
    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(-1.0, -1.0));
    ASSERT_DOUBLE_EQ(0.0, kernel1.Value(0.0, -1.0));

    // kernel outer

    ASSERT_DOUBLE_EQ(0.0, kernel2.Value(0.0, 0.0));

    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(1.0, 0.0));
    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(1.0, 1.0));
    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(0.0, 1.0));
    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(-1.0, 1.0));

    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(0.0, -1.0));
    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(-1.0, 0.0));
    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(-1.0, -1.0));
    ASSERT_DOUBLE_EQ(1.0 / 8.0, kernel2.Value(0.0, -1.0));
}

}  // namespace ca
