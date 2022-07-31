#pragma once

#include "../grid/rect_grid.h"

namespace ca {
namespace game_of_life {

void Process(const RectGrid& grid1, RectGrid& grid2, const int x, const int y);
void Process(RectGrid& grid1, RectGrid& grid2);

uint CountNeighbourhood(const RectGrid& grid, const int x, const int y);

}  // namespace game_of_life
}  // namespace ca
