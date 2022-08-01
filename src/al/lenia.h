#pragma once

#include "../grid/grid.h"
#include "growth_mapping.h"
#include "kernel.h"

namespace ca {

struct Config {
    uint x = 1;
    uint y = 1;
    kernel::Type type = kernel::GAME_OF_LIFE;
    double dt = 1.0;
};

class Lenia {
   public:
    Lenia();
    ~Lenia() = default;

    void SetConfig(const Config& config);
    void Reset();
    void Process();

    Grid grid1_;
    Grid grid2_;

   private:
    void Process(const Grid& grid1, Grid& grid2, const int x, const int y);

    Config config_;
};

}  // namespace ca
