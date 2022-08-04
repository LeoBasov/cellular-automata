#pragma once

#include "../exception/exception.h"
#include "kernel.h"
#include "kernel_algorithms.h"
#include "rectangular.h"

namespace ca {

using namespace kernel_algorithms;

class GameOfLife : public Kernel {
   public:
    GameOfLife();
    ~GameOfLife() = default;

    double Value(const double& x_diff, const double& y_diff) const override;

   private:
    Rectangular kernel_inner_;
    Rectangular kernel_outer_;
};

}  // namespace ca
