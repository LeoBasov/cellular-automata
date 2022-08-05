#pragma once

#include "../grid/grid.h"

namespace ca {

using uint = unsigned int;

class Kernel {
   public:
    Kernel();
    ~Kernel() = default;

    virtual double Value(const double& x_diff, const double& y_diff) const = 0;
    double Convolute(const Grid& grid, const int& x, const int& y, const int& radius) const;
    double GetNorm() const;

   protected:
    double norm_ = 1.0;
};

}  // namespace ca
