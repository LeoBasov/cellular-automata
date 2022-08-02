#pragma once

#include <cmath>

namespace ca {
namespace gui_algorithms {

using uint = unsigned int;
const double factor = 255.0;

uint Red(const double& value);
uint Green(const double& value);
uint Blue(const double& value);

}  // namespace gui_algorithms
}  // namespace ca
