#pragma once

#include <memory>

#include "../grid/grid.h"
#include "../kernel/exponential.h"
#include "../kernel/fast_game_of_life.h"
#include "../kernel/game_of_life.h"
#include "growth_mapping.h"
#include "kernel.h"

namespace ca {

class Lenia {
   public:
    struct Config {
        uint x = 1;
        uint y = 1;
        uint radius = 1;
        kernel::Type kernl_type = kernel::GAME_OF_LIFE;
        growth_mapping::Type growth_type = growth_mapping::RECTANGULAR;
        double dt = 1.0;
        double mu = 0.0;
        double sigma = 1.0;

        void GameOfLife() {
            radius = 1;
            kernl_type = kernel::GAME_OF_LIFE;
            growth_type = growth_mapping::RECTANGULAR;
            dt = 1.0;
            mu = 0.35;
            sigma = 0.07;
        }

        void Lenia() {
            radius = 12;
            kernl_type = kernel::EXPONENTIAL;
            growth_type = growth_mapping::EXPONENTIAL;
            dt = 0.1;
            mu = 0.15;
            sigma = 0.016;
        }
    };

    Lenia();
    ~Lenia() = default;

    void SetConfig(const Config& config);
    void Process();

    double& value(int x, int y);
    const double& value(int x, int y) const;

    size_t size_x() const;
    size_t size_y() const;

   private:
    Config config_;
    FastGrid grid_;
    FastGameOfLife gof_;
};

}  // namespace ca
