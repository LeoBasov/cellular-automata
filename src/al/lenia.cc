#include "lenia.h"

namespace ca {

Lenia::Lenia() { Reset(); }

void Lenia::SetConfig(const Config& config) {
    config_ = config;
    grid1_ = Grid(config_.x, config_.y);
    grid2_ = Grid(config_.x, config_.y);

    switch (config_.kernl_type) {
        case kernel::GAME_OF_LIFE: {
            kernel_ = std::make_shared<GameOfLife>();
            break;
        }
        case kernel::EXPONENTIAL: {
            std::shared_ptr<Exponential> kernel = std::make_shared<Exponential>();

            kernel->SetUp(config_.radius);
            kernel_ = kernel;

            break;
        }
        default:
            throw Exception("undefinied kernel", __PRETTY_FUNCTION__);
            break;
    }

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
    const double convolution = kernel_->Convolute(grid1, x, y, config_.radius);
    const double growth = growth_mapping::Growth(convolution, config_.mu, config_.sigma, config_.growth_type);

    grid2.value(x, y) = grid1.value(x, y) + config_.dt * growth;
    grid2.value(x, y) = std::min(1.0, std::max(0.0, grid2.value(x, y)));
}

double& Lenia::value(int x, int y) { return grid1_.active_ ? grid1_.value(x, y) : grid2_.value(x, y); }

const double& Lenia::value(int x, int y) const { return grid1_.active_ ? grid1_.value(x, y) : grid2_.value(x, y); }

double& Lenia::last_value(int x, int y) { return !grid1_.active_ ? grid1_.value(x, y) : grid2_.value(x, y); }

const double& Lenia::last_value(int x, int y) const {
    return !grid1_.active_ ? grid1_.value(x, y) : grid2_.value(x, y);
}

size_t Lenia::size_x() const { return grid1_.size_x(); }

size_t Lenia::size_y() const { return grid1_.size_y(); }

}  // namespace ca
