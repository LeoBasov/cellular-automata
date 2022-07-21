#include "game_of_life.h"

namespace ca {
namespace game_of_life {

void Process(const Grid& grid1, Grid& grid2, const uint idx) {
    const uint count = CountNeighbourhood(grid1, idx);

    if ((grid1.value(idx) == 1.0) && (count == 2 || count == 3)) {
        grid2.value(idx) = 1.0;
    } else if ((grid1.value(idx) == 0.0) && (count == 3)) {
        grid2.value(idx) = 1.0;
    } else {
        grid2.value(idx) = 0.0;
    }
}

uint CountNeighbourhood(const Grid& grid, const uint idx) {
    uint count = 0;
    Pair coords = grid.coords(idx);

    grid.CoordXMinus(coords);
    count += grid.value(coords);

    grid.CoordYMinus(coords);
    count += grid.value(coords);

    grid.CoordXPlus(coords);
    count += grid.value(coords);

    grid.CoordXPlus(coords);
    count += grid.value(coords);

    grid.CoordYPlus(coords);
    count += grid.value(coords);

    grid.CoordYPlus(coords);
    count += grid.value(coords);

    grid.CoordXMinus(coords);
    count += grid.value(coords);

    grid.CoordXMinus(coords);
    count += grid.value(coords);

    return count;
}

uint CountNeighbourhood(const Grid& grid, const Pair coords) { return CountNeighbourhood(grid, grid.idx(coords)); }

}  // namespace game_of_life
}  // namespace ca
