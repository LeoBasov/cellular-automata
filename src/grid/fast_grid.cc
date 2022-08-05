#include "fast_grid.h"

namespace ca {

FastGrid::FastGrid() {}

FastGrid::FastGrid(int x, int y) : x_(x), y_(y) { grid_ = VectorXd::Zero(x * y); }

}  // namespace ca
