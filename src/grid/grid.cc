#include "grid.h"

namespace ca {

Grid::Grid() { grid_ = VectorXd::Zero(x_ * y_); }

Grid::Grid(int x, int y) : x_(x), y_(y) { grid_ = VectorXd::Zero(x_ * y_); }

}  // namespace ca
