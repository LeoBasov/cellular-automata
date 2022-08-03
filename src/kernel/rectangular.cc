#include "rectangular.h"

namespace ca {

Rectangular::Rectangular() : Kernel() {}

void Rectangular::SetUp(const double& min, const double& max) {
    double count_outer = 0.0;
    double count_inner = 0.0;

    if (min >= max) {
        throw Exception("min >= max", __PRETTY_FUNCTION__);
    }

    min_ = min;
    max_ = max;

    for (int dx = 0; dx <= std::ceil(max_); dx++) {
        for (int dy = 0; dy <= std::ceil(max_); dy++) {
            if (Radius(dx, dy) <= max_) {
                count_outer += 1.0;
            }
        }
    }

    for (int dx = 0; dx <= std::ceil(min_); dx++) {
        for (int dy = 0; dy <= std::ceil(min_); dy++) {
            if (Radius(dx, dy) <= min_) {
                count_inner += 1.0;
            }
        }
    }

    norm_ = 0.25 / (count_outer - count_inner);
}

double Rectangular::Value(const double& x_diff, const double& y_diff) const {
    const double range = Radius(x_diff, y_diff);

    return (range >= min_) * (range <= max_) * norm_;
}

}  // namespace ca
