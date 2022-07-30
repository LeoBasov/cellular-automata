#pragma once

#include <utility>
#include <vector>

#include "../exception/exception.h"

namespace ca {

using uint = unsigned int;
using Pair = std::pair<uint, uint>;
using vector = std::vector<std::vector<double>>;

class RectGrid {
   public:
    RectGrid();
    RectGrid(uint x, uint y);
    ~RectGrid() = default;

    size_t size_x() const;
    size_t size_y() const;

    double& value(int x, int y);
    const double& value(int x, int y) const;

    bool active_ = false;

   private:
    vector values_ = vector(1, std::vector<double>(1, 0.0));
};

}  // namespace ca
