#pragma once

#include <memory>

#include "../kernel/kernel.h"
#include "growth_mapping.h"

namespace ca {

class Lenia {
   public:
    enum KernelType { GAME_OF_LIFE, EXPONENTIAL };

   public:
    struct Config {
        uint x = 1;
        uint y = 1;
        uint radius = 1;
        KernelType kernel_type = GAME_OF_LIFE;
        growth_mapping::Type growth_type = growth_mapping::RECTANGULAR;
        double dt = 1.0;
        double mu = 0.0;
        double sigma = 1.0;

        void GameOfLife() {
            radius = 1;
            kernel_type = GAME_OF_LIFE;
            growth_type = growth_mapping::RECTANGULAR;
            dt = 1.0;
            mu = 0.35;
            sigma = 0.07;
        }

        void Lenia() {
            radius = 12;
            kernel_type = EXPONENTIAL;
            growth_type = growth_mapping::EXPONENTIAL;
            dt = 0.1;
            mu = 0.135;
            sigma = 0.015;
        }
    };

    Lenia();
    ~Lenia() = default;

    void SetConfig(const Config& config);
    void Process();

    void ChangeKernel(KernelType kernl_type);

    double& value(int x, int y);
    const double& value(int x, int y) const;

    size_t size_x() const;
    size_t size_y() const;

   private:
    Config config_;
    Grid grid_;
    Kernel kernel_;
};

}  // namespace ca
