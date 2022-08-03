#pragma once

namespace ca {

using uint = unsigned int;

class Kernel {
   public:
    Kernel();
    Kernel(const double& radius);
    ~Kernel() = default;

    virtual double SetUp(const double& radius) const = 0;
    virtual double Value(const double& x_diff, const double& y_diff) const = 0;

   protected:
    double norm_ = 1.0;
};

}  // namespace ca
