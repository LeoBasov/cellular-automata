#pragma once

#include <Eigen/Dense>

namespace ca {

using namespace Eigen;

class FastGrid {
   public:
    FastGrid();
    FastGrid(int x, int y);
    ~FastGrid() = default;

    inline int idx(int x, int y) const {
        x = (x + x_) % x_;
        y = (y + y_) % y_;

        return y * x_ + x;
    }

    inline double& value(int x, int y) { return grid_(idx(x, y)); }

    inline const double& value(int x, int y) const { return grid_(idx(x, y)); }

    bool active_ = false;

    VectorXd grid_;
    int x_ = 1;
    int y_ = 1;
};

}  // namespace ca
