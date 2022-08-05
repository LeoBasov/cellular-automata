#include "fast_kernel.h"

namespace ca {

FastKernel::FastKernel() {}

void FastKernel::SetUpGameOfLife(const FastGrid& grid) {
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

void FastKernel::SetUpExponential(const FastGrid& grid, const double& radius) {
    const int size = grid.x_ * grid.y_;

    kernel_ = MatrixXd::Zero(size, size);
    norm_ = 0.0;

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            norm_ += Exp(dx, dy, radius);
        }
    }

    norm_ = 1.0 / norm_;

    for (int x = 0; x < grid.x_; x++) {
        for (int y = 0; y < grid.y_; y++) {
            for (int dx = -radius; dx <= radius; dx++) {
                for (int dy = -radius; dy <= radius; dy++) {
                    const int idx = grid.idx(x, y);
                    const int idx_p = grid.idx(x + dx, y + dy);

                    kernel_(idx_p, idx) = Exp(dx, dy, radius) * norm_;
                }
            }
        }
    }
}

}  // namespace ca
