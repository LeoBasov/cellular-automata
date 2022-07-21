#include "grid.h"

namespace ca {

Grid::Grid() {}

Grid::Grid(uint x, uint y) : x_(x), y_(y), values_(x_ * y_, 0.0) {}

uint Grid::x() const { return x_; }

uint Grid::y() const { return y_; }

const Vector& Grid::values() const { return values_; }

Pair Grid::coords(uint idx) const {
    Pair pair;

    pair.first = idx % x_;
    pair.second = idx / x_;

    return pair;
}

uint Grid::idx(const Pair& coords) const {
    if (coords.first >= x_) {
        throw Exception("coord.first >= x", __PRETTY_FUNCTION__);
    } else if (coords.second >= y_) {
        throw Exception("coord.second >= y", __PRETTY_FUNCTION__);
    }

    return coords.second * x_ + coords.first;
}

uint Grid::size() const { return values_.size(); }

double& Grid::value(uint idx) { return values_.at(idx); }

const double& Grid::value(uint idx) const { return values_.at(idx); }

double& Grid::value(const Pair& coords) { return value(idx(coords)); }

const double& Grid::value(const Pair& coords) const { return value(idx(coords)); }

}  // namespace ca
