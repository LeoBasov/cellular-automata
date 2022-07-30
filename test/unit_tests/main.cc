#include <gtest/gtest.h>

#include "game_of_life/game_of_life.h"
#include "grid/grid.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
