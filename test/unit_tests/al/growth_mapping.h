#pragma once

#include <gtest/gtest.h>

#include "../../../src/al/growth_mapping.h"

namespace ca {
namespace growth_mapping {

TEST(growth_mapping, Rectangular) {
    const double mu = 3.0;
    const double sigma = 5.0;
    const double value1 = 3.0;
    const double value2 = 8.1;
    const double value3 = -2.1;

    ASSERT_DOUBLE_EQ(1.0, Rectangular(value1, mu, sigma));
    ASSERT_DOUBLE_EQ(-1.0, Rectangular(value2, mu, sigma));
    ASSERT_DOUBLE_EQ(-1.0, Rectangular(value3, mu, sigma));
}

TEST(growth_mapping, Exponential) {
    const double mu = 3.0;
    const double sigma = 5.0;
    const double value1 = mu;
    const double value2 = mu + 2. * sigma;
    const double value3 = mu - 2. * sigma;

    ASSERT_DOUBLE_EQ(1.0, Exponential(value1, mu, sigma));
    ASSERT_TRUE(Exponential(value2, mu, sigma) < 0.0);
    ASSERT_TRUE(Exponential(value3, mu, sigma) < 0.0);
}

}  // namespace growth_mapping
}  // namespace ca
