#include "rect_grid.h"

namespace ca {

RectGrid::RectGrid() {}

RectGrid::RectGrid(uint x, uint y) : values_(vector(x, std::vector<double>(y, 0.0))) {}

size_t RectGrid::size_x() const { return values_.size(); }

size_t RectGrid::size_y() const { return values_.front().size(); }

double& RectGrid::value(int x, int y) {
    x = (x + size_x()) % size_x();
    y = (y + size_y()) % size_y();

    return values_.at(x).at(y);
}

const double& RectGrid::value(int x, int y) const {
    x = (x + size_x()) % size_x();
    y = (y + size_y()) % size_y();

    return values_.at(x).at(y);
}

}  // namespace ca
