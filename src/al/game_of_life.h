#pragma once

#include "../grid/grid.h"

namespace ca {
namespace game_of_life {

void Process(const Grid& grid1, Grid& grid2, const int x, const int y);
void Process(Grid& grid1, Grid& grid2);

uint CountNeighbourhood(const Grid& grid, const int x, const int y);

}  // namespace game_of_life
}  // namespace ca
