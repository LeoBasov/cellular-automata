#include <gtest/gtest.h>

#include "al/game_of_life.h"
#include "al/growth_mapping.h"
#include "al/kernel.h"
#include "al/lenia.h"
#include "grid/fast_grid.h"
#include "grid/grid.h"
#include "kernel/game_of_life.h"
#include "kernel/rectangular.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
