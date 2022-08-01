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

}  // namespace growth_mapping
}  // namespace ca
