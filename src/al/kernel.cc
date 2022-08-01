#include "kernel.h"

namespace ca {
namespace kernel {

double Rectangular(const double& x, const double& y, const double& min, const double& max) {
    const double range = std::sqrt(x * x + y * y) / norm_range;

    return (range >= min) * (range <= max);
}

}  // namespace kernel
}  // namespace ca
