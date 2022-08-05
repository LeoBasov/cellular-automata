#pragma once

#include <cmath>

namespace ca {
namespace kernel_algorithms {

inline double Radius(const double& x_diff, const double& y_diff) {
    return std::sqrt(x_diff * x_diff + y_diff * y_diff);
}

}  // namespace kernel_algorithms
}  // namespace ca
