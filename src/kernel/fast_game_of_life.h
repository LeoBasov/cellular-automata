#pragma once

#include <Eigen/Dense>

#include "../grid/fast_grid.h"

using namespace Eigen;

namespace ca {
class FastGameOfLife {
   public:
    FastGameOfLife();
    ~FastGameOfLife() = default;

    void SetUp(const FastGrid& grid);

    MatrixXd kernel_;
};
}  // namespace ca
