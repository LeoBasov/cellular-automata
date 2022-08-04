#include "kernel.h"

namespace ca {

Kernel::Kernel() {}

double Kernel::Convolute(const Grid& grid, const int& x, const int& y, const int& radius) const {
    double count = 0.0;

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            count += grid.value(x + dx, y + dy) * Value(dx, dy);
        }
    }

    return count;
}

double Kernel::GetNorm() const { return norm_; }

}  // namespace ca
