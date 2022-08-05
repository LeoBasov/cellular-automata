#pragma once

#include <gtest/gtest.h>

#include "../../../src/al/lenia.h"

namespace ca {

TEST(Lenia, GameOfLife_Block) {
    Lenia lenia1, lenia2;
    Lenia::Config config;

    config.GameOfLife();

    config.x = 4;
    config.y = 4;

    lenia1.SetConfig(config);
    lenia2.SetConfig(config);

    lenia1.value(1, 1) = 1.0;
    lenia1.value(2, 1) = 1.0;
    lenia1.value(1, 2) = 1.0;
    lenia1.value(2, 2) = 1.0;

    for (size_t x = 0; x < lenia1.size_x(); x++) {
        for (size_t y = 0; y < lenia1.size_y(); y++) {
            lenia2.value(x, y) = lenia1.value(x, y);
        }
    }

    lenia1.Process();

    for (size_t x = 0; x < lenia1.size_x(); x++) {
        for (size_t y = 0; y < lenia1.size_y(); y++) {
            ASSERT_DOUBLE_EQ(lenia1.value(x, y), lenia2.value(x, y));
        }
    }
}

TEST(Lenia, GameOfLife_BeeHive) {
    Lenia lenia1, lenia2;
    Lenia::Config config;

    config.GameOfLife();

    config.x = 5;
    config.y = 6;

    lenia1.SetConfig(config);
    lenia2.SetConfig(config);

    lenia1.value(1, 2) = 1.0;
    lenia1.value(4, 2) = 1.0;

    lenia1.value(2, 1) = 1.0;
    lenia1.value(3, 1) = 1.0;

    lenia1.value(2, 3) = 1.0;
    lenia1.value(3, 3) = 1.0;

    for (size_t x = 0; x < lenia1.size_x(); x++) {
        for (size_t y = 0; y < lenia1.size_y(); y++) {
            lenia2.value(x, y) = lenia1.value(x, y);
        }
    }

    lenia1.Process();

    for (size_t x = 0; x < lenia1.size_x(); x++) {
        for (size_t y = 0; y < lenia1.size_y(); y++) {
            ASSERT_DOUBLE_EQ(lenia1.value(x, y), lenia2.value(x, y));
        }
    }
}

TEST(Lenia, GameOfLife_Blinker) {
    Lenia lenia;
    Lenia::Config config;

    config.GameOfLife();

    config.x = 5;
    config.y = 5;

    lenia.SetConfig(config);

    lenia.value(2, 3) = 1.0;
    lenia.value(2, 2) = 1.0;
    lenia.value(2, 1) = 1.0;

    lenia.Process();

    ASSERT_DOUBLE_EQ(1.0, lenia.value(1, 2));
    ASSERT_DOUBLE_EQ(1.0, lenia.value(2, 2));
    ASSERT_DOUBLE_EQ(1.0, lenia.value(3, 2));
}

TEST(Lenia, GameOfLife_Glider) {
    Lenia lenia;
    Lenia::Config config;

    config.GameOfLife();

    config.x = 6;
    config.y = 6;

    lenia.SetConfig(config);

    lenia.value(1, 3) = 1.0;
    lenia.value(2, 2) = 1.0;
    lenia.value(3, 2) = 1.0;
    lenia.value(3, 3) = 1.0;
    lenia.value(3, 4) = 1.0;

    lenia.Process();

    ASSERT_DOUBLE_EQ(1.0, lenia.value(2, 2));
    ASSERT_DOUBLE_EQ(1.0, lenia.value(2, 4));

    ASSERT_DOUBLE_EQ(1.0, lenia.value(3, 2));
    ASSERT_DOUBLE_EQ(1.0, lenia.value(3, 3));

    ASSERT_DOUBLE_EQ(1.0, lenia.value(4, 3));

    lenia.Process();

    ASSERT_DOUBLE_EQ(1.0, lenia.value(2, 2));

    ASSERT_DOUBLE_EQ(1.0, lenia.value(3, 2));
    ASSERT_DOUBLE_EQ(1.0, lenia.value(3, 4));

    ASSERT_DOUBLE_EQ(1.0, lenia.value(4, 2));
    ASSERT_DOUBLE_EQ(1.0, lenia.value(4, 3));
}

}  // namespace ca
