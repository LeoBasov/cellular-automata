#pragma once

#include <Eigen/Dense>

namespace ca {

using namespace Eigen;

class FastGrid {
   public:
    FastGrid();
    ~FastGrid() = default;

    inline double& value(int x, int y) {
        x = (x + x_) % x_;
        y = (y + y_) % y_;

        return grid_(y * y_ + x);
    }

    bool active_ = false;

    VectorXd grid_;
    int x_ = 1;
    int y_ = 1;
};

}  // namespace ca
