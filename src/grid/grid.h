#pragma once

#include <utility>
#include <vector>

#include "../exception/exception.h"

namespace ca {

using uint = unsigned int;
using Pair = std::pair<uint, uint>;
using vector = std::vector<std::vector<double>>;

class Grid {
   public:
    Grid();
    Grid(uint x, uint y);
    ~Grid() = default;

    size_t size_x() const;
    size_t size_y() const;

    inline double& value(int x, int y) {
        x = (x + size_x()) % size_x();
        y = (y + size_y()) % size_y();

        return values_.at(x).at(y);
    }

    inline const double& value(int x, int y) const {
        x = (x + size_x()) % size_x();
        y = (y + size_y()) % size_y();

        return values_.at(x).at(y);
    }

    bool active_ = false;

   private:
    vector values_ = vector(1, std::vector<double>(1, 0.0));
};

}  // namespace ca
