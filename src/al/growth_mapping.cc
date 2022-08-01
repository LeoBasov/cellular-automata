#include "growth_mapping.h"

namespace ca {
namespace growth_mapping {

double Rectangular(const double &value, const double &mu, const double &sigma) {
    return 2.0 * ((value >= (mu - sigma)) * (value <= (mu + sigma))) - 1.0;
}

}  // namespace growth_mapping
}  // namespace ca
