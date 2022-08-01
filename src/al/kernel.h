#pragma once

#include <cmath>

#include "../grid/grid.h"

namespace ca {
namespace kernel {

const double norm_range = 4.0;

double Rectangular(const double& x, const double& y, const double& min, const double& max);

}  // namespace kernel
}  // namespace ca
