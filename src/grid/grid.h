#pragma once

#include <utility>

namespace ca {

using uint = unsigned int;
using Pair = std::pair<uint, uint>;

class Grid {
   public:
    Grid();
    Grid(uint x, uint y);
    ~Grid() = default;

    uint x() const;
    uint y() const;
    Pair Coords(uint idx) const;

   private:
    uint x_ = 1;
    uint y_ = 1;
};

}  // namespace ca
