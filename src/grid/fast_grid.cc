#include "fast_grid.h"

namespace ca {

FastGrid::FastGrid() { grid_ = VectorXd::Zero(x_ * y_); }

FastGrid::FastGrid(int x, int y) : x_(x), y_(y) { grid_ = VectorXd::Zero(x_ * y_); }

}  // namespace ca
