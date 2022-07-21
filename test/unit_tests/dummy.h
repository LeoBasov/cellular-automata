#pragma once

#include <gtest/gtest.h>

#include "../../src/dummy.h"

namespace ca {

TEST(dummy, Test) {
    const int input = 12;
    const int ref = 13;
    const int result = dummy::Test(input);

    ASSERT_EQ(ref, result);
}

}  // namespace ca
