#include "lenia.h"

namespace ca {

Lenia::Lenia() {}

void Lenia::SetConfig(const Config& config) {
    config_ = config;
    grid_ = FastGrid(config_.x, config_.y);
    gof_.SetUp(grid_);
}

void Lenia::Process() {
    grid_.grid_ = gof_.kernel_ * grid_.grid_;

    for (int x = 0; x < grid_.x_; x++) {
        for (int y = 0; y < grid_.y_; y++) {
            const double growth =
                growth_mapping::Growth(grid_.value(x, y), config_.mu, config_.sigma, config_.growth_type);

            grid_.value(x, y) += config_.dt * growth;
            grid_.value(x, y) = std::min(1.0, std::max(0.0, grid_.value(x, y)));
        }
    }
}

double& Lenia::value(int x, int y) { return grid_.value(x, y); }

const double& Lenia::value(int x, int y) const { return grid_.value(x, y); }

size_t Lenia::size_x() const { return grid_.x_; }

size_t Lenia::size_y() const { return grid_.y_; }

}  // namespace ca
