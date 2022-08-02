#include "growth_mapping.h"

namespace ca {
namespace growth_mapping {

double Growth(const double& value, const double& mu, const double& sigma, const Type& type) {
    switch (type) {
        case RECTANGULAR: {
            return Rectangular(value, mu, sigma);
            break;
        }
        case EXPONENTIAL: {
            return Rectangular(value, mu, sigma);
            break;
        }
        default: {
            throw Exception("undefined case", __PRETTY_FUNCTION__);
            break;
        }
    }
}

double Rectangular(const double &value, const double &mu, const double &sigma) {
    return 2.0 * ((value >= (mu - sigma)) * (value <= (mu + sigma))) - 1.0;
}

double Exponential(const double& value, const double& mu, const double& sigma) {
    return 2.0 * std::exp(-std::pow(value - mu, 2) / (2.0 * sigma * sigma)) - 1.0;
}

}  // namespace growth_mapping
}  // namespace ca
