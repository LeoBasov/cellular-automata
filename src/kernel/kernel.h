#pragma once

namespace ca {

using uint = unsigned int;

class Kernel {
   public:
    Kernel();
    ~Kernel() = default;

    virtual double Value(const double& x_diff, const double& y_diff) const = 0;
    double GetNorm() const;

   protected:
    double norm_ = 1.0;
};

}  // namespace ca
