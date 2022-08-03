#include "kernel.h"

namespace ca {
namespace kernel {

double Kernel(const Grid& grid, const int& x, const int& y, const int& radius, const Type& type) {
    double count = 0.0;

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            count += Kernel(grid.value(x + dx, y + dy), dx, dy, radius, type);
        }
    }

    return count;
}

double Kernel(const double& value, const int& x_diff, const int y_diff, const double& radius, const Type& type) {
    switch (type) {
        case GAME_OF_LIFE: {
            return value * GameOfLife(x_diff, y_diff, radius);
            break;
        }
        case MOORE: {
            return value * Moore(x_diff, y_diff, radius);
            break;
        }
        case FULL: {
            return value * Full(x_diff, y_diff, radius);
            break;
        }
        case EXPONENTIAL: {
            return value * Exponential(x_diff, y_diff, radius);
            break;
        }
        default: {
            throw Exception("undefined case", __PRETTY_FUNCTION__);
            break;
        }
    }
}

double Range(const int& x_diff, const int y_diff, const double& radius) {
    return std::sqrt(x_diff * x_diff + y_diff * y_diff) / radius;
}

double Rectangular(const double& x_diff, const double& y_diff, const double& radius, const double& min, const double& max) {
    const double range = Range(x_diff, y_diff, radius);

    return (range >= min) * (range <= max);
}

double Exponential(const double& x_diff, const double& y_diff, const double& radius, const double& alpha) {
    const double range = Range(x_diff, y_diff, radius);

    return std::exp(alpha - alpha / (4.0 * range * (1.0 - range)));
}

double GameOfLife(const double& x_diff, const double& y_diff, const double& radius) {
    return (Rectangular(x_diff, y_diff, radius, 1.0, 1.42) + 0.5 * Rectangular(x_diff, y_diff, radius, 0.0, 0.8)) / 8.5;
}

double Moore(const double& x_diff, const double& y_diff, const double& radius) { return Rectangular(x_diff, y_diff, radius, 0.0, 1.42); }

double Full(const double& x_diff, const double& y_diff, const double &radius) { return Rectangular(x_diff, y_diff, radius, 0.0, 1.06); }

}  // namespace kernel
}  // namespace ca
