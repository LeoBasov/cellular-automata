#pragma once

#include "../grid/grid.h"
#include "../grid/rect_grid.h"

namespace ca {
namespace game_of_life {

void Process(const Grid& grid1, Grid& grid2, const uint idx);
void Process(const RectGrid& grid1, RectGrid& grid2, const int x, const int y);

uint CountNeighbourhood(const Grid& grid, const uint idx);
uint CountNeighbourhood(const Grid& grid, const Pair idx);

uint CountNeighbourhood(const RectGrid& grid, const int x, const int y);

}  // namespace game_of_life
}  // namespace ca
