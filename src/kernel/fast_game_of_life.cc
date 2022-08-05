#include "fast_game_of_life.h"

namespace ca {

FastGameOfLife::FastGameOfLife() {}

void FastGameOfLife::SetUp(const FastGrid &grid) {
    const int size = grid.x_ * grid.y_;
    kernel_ = MatrixXd::Zero(size, size);

    for (int x = 0; x < grid.x_; x++) {
        for (int y = 0; y < grid.y_; y++) {
            const int idx = grid.idx(x, y);
            const int idx_xm = grid.idx(x - 1, y);
            const int idx_xp = grid.idx(x + 1, y);
            const int idx_ym = grid.idx(x, y - 1);
            const int idx_yp = grid.idx(x, y + 1);

            kernel_(idx, idx) = 0.5;
            kernel_(idx_xm, idx) = 1.0;
            kernel_(idx_xp, idx) = 1.0;
            kernel_(idx_ym, idx) = 1.0;
            kernel_(idx_yp, idx) = 1.0;
        }
    }
}

}  // namespace ca
