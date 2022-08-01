#include "lenia.h"

namespace ca {

Lenia::Lenia() { Reset(); }

void Lenia::SetConfig(const Config& config) {
    config_ = config;
    grid1_ = Grid(config_.x, config_.y);
    grid2_ = Grid(config_.x, config_.y);

    Reset();
}

void Lenia::Reset() {
    grid1_.active_ = true;
    grid2_.active_ = false;
}

void Lenia::Process() {
    if (grid1_.active_ && (!grid2_.active_)) {
        for (size_t x = 0; x < grid1_.size_x(); x++) {
            for (size_t y = 0; y < grid1_.size_y(); y++) {
                Process(grid1_, grid2_, x, y);
            }
        }

        grid1_.active_ = false;
        grid2_.active_ = true;
    } else if ((!grid1_.active_) && grid2_.active_) {
        for (size_t x = 0; x < grid1_.size_x(); x++) {
            for (size_t y = 0; y < grid1_.size_y(); y++) {
                Process(grid2_, grid1_, x, y);
            }
        }

        grid1_.active_ = true;
        grid2_.active_ = false;
    } else {
        throw Exception("wrong active state of grids", __PRETTY_FUNCTION__);
    }
}

void Lenia::Process(const Grid& grid1, Grid& grid2, const int x, const int y) {
    const double convolution = kernel::Kernel(grid1, x, y, config_.type);

    grid2.value(x, y) += config_.dt * convolution;
    grid2.value(x, y) = std::min(1.0, std::max(0.0, grid2.value(x, y)));
}

}  // namespace ca
