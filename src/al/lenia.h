#pragma once

#include "../grid/grid.h"
#include "growth_mapping.h"
#include "kernel.h"

namespace ca {

class Lenia {
   public:
    struct Config {
        uint x = 1;
        uint y = 1;
        uint radius = 1;
        kernel::Type type = kernel::GAME_OF_LIFE;
        double dt = 1.0;
        double mu = 0.0;
        double sigma = 1.0;
    };

    Lenia();
    ~Lenia() = default;

    void SetConfig(const Config& config);
    void Reset();
    void Process();

    double& value(int x, int y);
    const double& value(int x, int y) const;

    double& last_value(int x, int y);
    const double& last_value(int x, int y) const;

    size_t size_x() const;
    size_t size_y() const;

   private:
    void Process(const Grid& grid1, Grid& grid2, const int x, const int y);

    Config config_;
    Grid grid1_;
    Grid grid2_;
};

}  // namespace ca
