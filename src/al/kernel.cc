#include "kernel.h"

namespace ca {

double Rectangular(const Grid& grid, const int& x, const int& y) {
    double count = 0;

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

}  // namespace ca
