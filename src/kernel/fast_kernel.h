#pragma once

#include <Eigen/Dense>

#include "../grid/fast_grid.h"

using namespace Eigen;

namespace ca {
class FastKernel {
   public:
    FastKernel();
    ~FastKernel() = default;

    void SetUp(const FastGrid& grid);

    MatrixXd kernel_;
};
}  // namespace ca
