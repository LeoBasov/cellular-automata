#include "fast_game_of_life.h"

namespace ca {

FastGameOfLife::FastGameOfLife() {}

void FastGameOfLife::SetUp(const FastGrid &grid) {
    const int size = grid.x_ * grid.y_;
    const double factor = 1.0 / 8.5;
    kernel_ = MatrixXd::Zero(size, size);

    for (int x = 0; x < grid.x_; x++) {
        for (int y = 0; y < grid.y_; y++) {
            const int idx = grid.idx(x, y);
            const int idx_1 = grid.idx(x - 1, y);
            const int idx_2 = grid.idx(x - 1, y - 1);
            const int idx_3 = grid.idx(x, y - 1);
            const int idx_4 = grid.idx(x + 1, y - 1);
            const int idx_5 = grid.idx(x + 1, y);
            const int idx_6 = grid.idx(x + 1, y + 1);
            const int idx_7 = grid.idx(x, y + 1);
            const int idx_8 = grid.idx(x - 1, y + 1);

            kernel_(idx, idx) = 0.5 * factor;
            kernel_(idx_1, idx) = factor;
            kernel_(idx_2, idx) = factor;
            kernel_(idx_3, idx) = factor;
            kernel_(idx_4, idx) = factor;
            kernel_(idx_5, idx) = factor;
            kernel_(idx_6, idx) = factor;
            kernel_(idx_7, idx) = factor;
            kernel_(idx_8, idx) = factor;
        }
    }
}

}  // namespace ca
