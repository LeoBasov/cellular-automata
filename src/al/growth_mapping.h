#pragma once

#include <cmath>

#include "../exception/exception.h"

namespace ca {
namespace growth_mapping {

enum Type { RECTANGULAR, EXPONENTIAL };

double Growth(const double& value, const double& mu, const double& sigma, const Type& type);

double Rectangular(const double& value, const double& mu, const double& sigma);
double Exponential(const double& value, const double& mu, const double& sigma);

}  // namespace growth_mapping
}  // namespace ca
