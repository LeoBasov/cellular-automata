#include "grid.h"

namespace ca {

Grid::Grid() {}

Grid::Grid(uint x, uint y) : x_(x), y_(y) {}

uint Grid::x() const { return x_; }

uint Grid::y() const { return y_; }

Pair Grid::Coords(uint idx) const {
    Pair pair;

    pair.first = idx % x_;
    pair.second = idx / x_;

    return pair;
}

}  // namespace ca
