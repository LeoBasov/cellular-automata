#pragma once

#include "../grid/grid.h"

namespace ca {
namespace game_of_life {

void Process(const Grid& grid1, Grid& grid2, const uint idx);
uint CountNeighbourhood(const Grid& grid, const uint idx);
uint CountNeighbourhood(const Grid& grid, const Pair idx);

}  // namespace game_of_life
}  // namespace ca
