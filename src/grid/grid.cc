#include "grid.h"

namespace ca {

Grid::Grid() {}

Grid::Grid(uint x, uint y) : values_(vector(x, std::vector<double>(y, 0.0))) {}

size_t Grid::size_x() const { return values_.size(); }

size_t Grid::size_y() const { return values_.front().size(); }

}  // namespace ca
