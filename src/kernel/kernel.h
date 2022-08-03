#pragma once

namespace ca {

using uint = unsigned int;

class Kernel {
   public:
    Kernel();
    ~Kernel() = default;

    virtual void SetUp(const double& radius) = 0;
    virtual double Value(const double& x_diff, const double& y_diff) const = 0;

   protected:
    double norm_ = 1.0;
};

}  // namespace ca
