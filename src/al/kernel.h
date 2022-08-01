#pragma once

#include <cmath>

#include "../grid/grid.h"

namespace ca {
namespace kernel {

const double norm_range = 4.0;

enum Type { GAME_OF_LIFE, MOORE };

double Kernel(const Grid& grid, const uint& x, const uint& y, Type type);
double Kernel(const double& value, const int& x_diff, const int y_diff, Type type);
double Rectangular(const double& x_diff, const double& y_diff, const double& min, const double& max);

// implementation
double GameOfLife(const double& x_diff, const double& y_diff);
double Moore(const double& x_diff, const double& y_diff);

}  // namespace kernel
}  // namespace ca
