#pragma once

#include "kernel.h"
#include "kernel_algorithms.h"

namespace ca {

using namespace kernel_algorithms;

class Exponential : public Kernel {
   public:
    Exponential();
    ~Exponential() = default;

    void SetUp(const double& radius, const double& alpha = 4.0);
    double Exp(const double& x_diff, const double& y_diff) const;
    virtual double Value(const double& x_diff, const double& y_diff) const override;

   private:
    double radius_ = 1.0;
    double alpha_ = 4.0;
};

}  // namespace ca
