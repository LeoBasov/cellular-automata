#include "game_of_life.h"

namespace ca {
namespace game_of_life {

void Process(const RectGrid& grid1, RectGrid& grid2, const int x, const int y) {
    const uint count = CountNeighbourhood(grid1, x, y);

    if ((grid1.value(x, y) == 1.0) && (count == 2 || count == 3)) {
        grid2.value(x, y) = 1.0;
    } else if ((grid1.value(x, y) == 0.0) && (count == 3)) {
        grid2.value(x, y) = 1.0;
    } else {
        grid2.value(x, y) = 0.0;
    }
}

void Process(RectGrid& grid1, RectGrid& grid2) {
    if (grid1.active_ && (!grid2.active_)) {
        for (size_t x = 0; x < grid1.size_x(); x++) {
            for (size_t y = 0; y < grid1.size_y(); y++) {
                Process(grid1, grid2, x, y);
            }
        }

        grid1.active_ = false;
        grid2.active_ = true;
    } else if ((!grid1.active_) && grid2.active_) {
        for (size_t x = 0; x < grid1.size_x(); x++) {
            for (size_t y = 0; y < grid1.size_y(); y++) {
                Process(grid2, grid1, x, y);
            }
        }

        grid1.active_ = true;
        grid2.active_ = false;
    } else {
        throw Exception("wrong active state of grids", __PRETTY_FUNCTION__);
    }
}

uint CountNeighbourhood(const RectGrid& grid, const int x, const int y) {
    uint count = 0;

    count += grid.value(x - 1, y);
    count += grid.value(x - 1, y - 1);
    count += grid.value(x, y - 1);
    count += grid.value(x + 1, y - 1);
    count += grid.value(x + 1, y);
    count += grid.value(x + 1, y + 1);
    count += grid.value(x, y + 1);
    count += grid.value(x - 1, y + 1);

    return count;
}

}  // namespace game_of_life
}  // namespace ca
