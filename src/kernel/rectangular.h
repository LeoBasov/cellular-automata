#pragma once

#include "../exception/exception.h"
#include "kernel.h"
#include "kernel_algorithms.h"

namespace ca {

using namespace kernel_algorithms;

class Rectangular : public Kernel {
   public:
    Rectangular();
    ~Rectangular() = default;

    void SetUp(const double& min, const double& max);
    double Value(const double& x_diff, const double& y_diff) const override;

   private:
    double min_ = 0.0;
    double max_ = 1.0;
};

}  // namespace ca
