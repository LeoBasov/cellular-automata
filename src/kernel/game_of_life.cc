#include "game_of_life.h"

namespace ca {

GameOfLife::GameOfLife() : Kernel() {
    norm_ = 1 / 8.5;
    kernel_inner_.SetUp(0, 0.25);
    kernel_outer_.SetUp(0.25, std::sqrt(2));
}

double GameOfLife::Value(const double& x_diff, const double& y_diff) const {
    return (0.5 * kernel_inner_.Value(x_diff, y_diff) + kernel_outer_.Value(x_diff, y_diff) * 8.0) * norm_;
}

}  // namespace ca
