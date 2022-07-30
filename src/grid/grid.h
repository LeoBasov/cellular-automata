#pragma once

#include <utility>
#include <vector>

#include "../exception/exception.h"

namespace ca {

using uint = unsigned int;
using Pair = std::pair<uint, uint>;
using Vector = std::vector<double>;

class Grid {
   public:
    Grid();
    Grid(uint x, uint y);
    ~Grid() = default;

    uint x() const;
    uint y() const;
    const Vector& values() const;
    Pair coords(uint idx) const;
    uint idx(const Pair& coords) const;
    uint size() const;
    double& value(uint idx);
    const double& value(uint idx) const;
    double& value(const Pair& coords);
    const double& value(const Pair& coords) const;

    void CoordXPlus(Pair& coords) const;
    void CoordXMinus(Pair& coords) const;
    void CoordYPlus(Pair& coords) const;
    void CoordYMinus(Pair& coords) const;

    uint CoordXPlus(const uint& idx) const;
    uint CoordXMinus(const uint& idx) const;

    bool active_ = false;

   private:
    uint x_ = 1;
    uint y_ = 1;
    Vector values_ = Vector(x_ * y_, 0.0);
};

}  // namespace ca
