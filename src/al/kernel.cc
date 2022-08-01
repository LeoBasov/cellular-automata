#include "kernel.h"

namespace ca {
namespace kernel {

double Rectangular(const double& x, const double& y, const double& min, const double& max) {
    const double range = std::sqrt(x * x + y * y) / norm_range;

    return (range >= min) * (range <= max);
}

double GameOfLife(const double& x, const double& y) {
    return Rectangular(x, y, 0.25, 0.75) + 0.5 * Rectangular(x, y, 0.0, 0.25);
}

}  // namespace kernel
}  // namespace ca
