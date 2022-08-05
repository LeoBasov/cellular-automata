#pragma once

#include <cmath>

namespace ca {
namespace kernel_algorithms {

inline double Radius(const double& x_diff, const double& y_diff) {
    return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

inline double Exp(const double& x_diff, const double& y_diff, const double& radius) {
    const double radius__ = Radius(x_diff, y_diff) / radius;

    // return std::exp(-std::pow((radius-0.5)/0.15,2) / 2)*2.0 - 1.0;
    return std::exp(-std::pow((radius__ - 0.5) / 0.15, 2) / 2);
}

}  // namespace kernel_algorithms
}  // namespace ca
