#pragma once

#include <Eigen/Dense>

#include "../grid/fast_grid.h"
#include "kernel_algorithms.h"

namespace ca {

using namespace Eigen;
using namespace kernel_algorithms;

class FastKernel {
   public:
    FastKernel();
    ~FastKernel() = default;

    void SetUpGameOfLife(const FastGrid& grid);
    void SetUpExponential(const FastGrid& grid, const double& radius);

    MatrixXd kernel_;
    double norm_ = 1.0;
};

}  // namespace ca
