#include "rect_grid.h"

namespace ca {

RectGrid::RectGrid() {}

RectGrid::RectGrid(uint x, uint y) : values_(vector(x, std::vector<double>(y, 0.0))) {}

size_t RectGrid::size_x() const { return values_.size(); }

size_t RectGrid::size_y() const { return values_.front().size(); }

double& RectGrid::value(int x, int y) {
    x = x < 0 ? x % values_.size() : x;
    y = y < 0 ? y % values_.front().size() : y;

    return values_.at(x).at(y);
}

const double& RectGrid::value(int x, int y) const {
    return values_.at(x % values_.size()).at(y % values_.front().size());
}

}  // namespace ca
