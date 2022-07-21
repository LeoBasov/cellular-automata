#pragma once

#include <utility>
#include <vector>

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
    uint size() const;
    double& value(uint idx);
    const double& value(uint idx) const;

   private:
    uint x_ = 1;
    uint y_ = 1;
    Vector values_ = Vector(x_ * y_, 0.0);
};

}  // namespace ca
