#include "kernel.h"

namespace ca {
namespace kernel {

double Kernel(const Grid& grid, const int& x, const int& y, const Type& type) {
    double count = 0.0;

    count += Kernel(grid.value(x - 1, y - 1), 1, 1, type);
    count += Kernel(grid.value(x - 1, y + 0), 1, 0, type);
    count += Kernel(grid.value(x - 1, y + 1), 1, 1, type);

    count += Kernel(grid.value(x + 0, y - 1), 0, 1, type);
    count += Kernel(grid.value(x + 0, y + 0), 0, 0, type);
    count += Kernel(grid.value(x + 0, y + 1), 0, 1, type);

    count += Kernel(grid.value(x + 1, y - 1), 1, 1, type);
    count += Kernel(grid.value(x + 1, y + 0), 1, 0, type);
    count += Kernel(grid.value(x + 1, y + 1), 1, 1, type);

    // outer shell
    count += Kernel(grid.value(x + 1, y + 2), 1, 2, type);
    count += Kernel(grid.value(x, y + 2), 0, 2, type);
    count += Kernel(grid.value(x - 1, y + 2), 1, 2, type);
    count += Kernel(grid.value(x - 2, y + 2), 2, 2, type);

    count += Kernel(grid.value(x - 2, y + 1), 2, 1, type);
    count += Kernel(grid.value(x - 2, y), 2, 0, type);
    count += Kernel(grid.value(x - 2, y - 1), 2, 1, type);
    count += Kernel(grid.value(x - 2, y - 2), 2, 2, type);

    count += Kernel(grid.value(x - 1, y - 2), 1, 2, type);
    count += Kernel(grid.value(x, y - 2), 0, 2, type);
    count += Kernel(grid.value(x + 1, y - 2), 1, 2, type);
    count += Kernel(grid.value(x + 2, y - 2), 2, 2, type);

    count += Kernel(grid.value(x + 2, y - 1), 2, 1, type);
    count += Kernel(grid.value(x + 2, y), 2, 0, type);
    count += Kernel(grid.value(x + 2, y + 1), 2, 1, type);
    count += Kernel(grid.value(x + 2, y + 2), 2, 2, type);

    // rings
    count += Kernel(grid.value(x + 1, y + 3), 1, 3, type);
    count += Kernel(grid.value(x, y + 3), 0, 2, type);
    count += Kernel(grid.value(x - 1, y + 3), 1, 3, type);

    count += Kernel(grid.value(x - 3, y + 1), 3, 1, type);
    count += Kernel(grid.value(x - 3, y), 3, 0, type);
    count += Kernel(grid.value(x - 3, y - 1), 3, 1, type);

    count += Kernel(grid.value(x - 1, y - 3), 1, 3, type);
    count += Kernel(grid.value(x, y - 3), 0, 3, type);
    count += Kernel(grid.value(x + 1, y - 3), 1, 3, type);

    count += Kernel(grid.value(x + 3, y + 1), 3, 1, type);
    count += Kernel(grid.value(x + 3, y), 3, 0, type);
    count += Kernel(grid.value(x + 3, y - 1), 3, 1, type);

    return count;
}

double Kernel(const Grid& grid, const int& x, const int& y, const int& radius, const Type& type) {
    double count = 0.0;

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            count += Kernel(grid.value(x + dx, y + dy), dx, dy, type);
        }
    }

    return count;
}

double Kernel(const double& value, const int& x_diff, const int y_diff, const Type& type) {
    switch (type) {
        case GAME_OF_LIFE: {
            return value * GameOfLife(x_diff, y_diff);
            break;
        }
        case MOORE: {
            return value * Moore(x_diff, y_diff);
            break;
        }
        case FULL: {
            return value * Full(x_diff, y_diff);
            break;
        }
        default: {
            throw Exception("undefined case", __PRETTY_FUNCTION__);
            break;
        }
    }
}

double Rectangular(const double& x_diff, const double& y_diff, const double& min, const double& max) {
    const double range = std::sqrt(x_diff * x_diff + y_diff * y_diff) / norm_range;

    return (range >= min) * (range <= max);
}

double GameOfLife(const double& x_diff, const double& y_diff) {
    return Rectangular(x_diff, y_diff, 0.25, 0.4) + 0.5 * Rectangular(x_diff, y_diff, 0.0, 0.2);
}

double Moore(const double& x_diff, const double& y_diff) { return Rectangular(x_diff, y_diff, 0.0, 0.4); }

double Full(const double& x_diff, const double& y_diff) { return Rectangular(x_diff, y_diff, 0.0, 0.8); }

}  // namespace kernel
}  // namespace ca
