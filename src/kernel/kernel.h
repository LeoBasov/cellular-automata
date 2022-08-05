#pragma once

#include <Eigen/Dense>

#include "../grid/grid.h"
#include "kernel_algorithms.h"

namespace ca {

using namespace Eigen;
using namespace kernel_algorithms;

class Kernel {
   public:
    Kernel();
    ~Kernel() = default;

    void SetUpGameOfLife(const Grid& grid);
    void SetUpExponential(const Grid& grid, const double& radius);

    MatrixXd kernel_;
    double norm_ = 1.0;
};

}  // namespace ca
