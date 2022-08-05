#pragma once

#include <cmath>

namespace ca {
namespace kernel_algorithms {

inline double Radius(const double& x_diff, const double& y_diff) {
    return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

inline double Bell(const double& x, const double& m, const double& s) {
    return std::exp(-std::pow((x - m) / s, 2) / 2.0);
}

inline double Exp(const double& x_diff, const double& y_diff, const double& radius) {
    const double D = Radius(x_diff, y_diff) / radius;

    return (D < 1.0) * Bell(D, 0.5, 0.15);
}

}  // namespace kernel_algorithms
}  // namespace ca
