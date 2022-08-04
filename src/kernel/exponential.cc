#include "exponential.h"

namespace ca {

Exponential::Exponential() : Kernel() {}

void Exponential::SetUp(const double& radius, const double& alpha) {
    radius_ = radius;
    alpha_ = alpha;

    double count = 0.0;

    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            count += Exp(dx, dy);
        }
    }

    norm_ = 1.0 / count;
}

double Exponential::Exp(const double& x_diff, const double& y_diff) const {
    const double radius = Radius(x_diff, y_diff) / radius_;

    // return std::exp(-std::pow((radius-0.5)/0.15,2) / 2)*2.0 - 1.0;
    return std::exp(-std::pow((radius - 0.5) / 0.15, 2) / 2);
}

double Exponential::Value(const double& x_diff, const double& y_diff) const { return Exp(x_diff, y_diff) * norm_; }

}  // namespace ca
