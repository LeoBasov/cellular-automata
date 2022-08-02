#pragma once

#include <cmath>

#include "../grid/grid.h"

namespace ca {
namespace kernel {

enum Type { GAME_OF_LIFE, MOORE, FULL };

double Kernel(const Grid& grid, const int& x, const int& y, const int& radius, const Type& type);
double Kernel(const double& value, const int& x_diff, const int y_diff, const double &radius, const Type& type);
double Rectangular(const double& x_diff, const double& y_diff, const double& radius, const double& min, const double& max);

// implementation
double GameOfLife(const double& x_diff, const double& y_diff, const double& radius);
double Moore(const double& x_diff, const double& y_diff, const double& radius);
double Full(const double& x_diff, const double& y_diff, const double& radius);

}  // namespace kernel
}  // namespace ca
