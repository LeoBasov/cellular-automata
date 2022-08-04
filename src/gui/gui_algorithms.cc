#include "gui_algorithms.h"

namespace ca {
namespace gui_algorithms {

uint Red(const double& value) { return factor * (value >= 0.75) * (std::cos(2.0 * M_PI * value) + 1.0) * 0.5; }

uint Green(const double& value) { return factor * (std::cos(2.0 * M_PI * value + M_PI) + 1.0) * 0.5; }

uint Blue(const double& value) { return factor * (value <= 0.25) * (std::cos(2.0 * M_PI * value) + 1.0) * 0.5; }

}  // namespace gui_algorithms
}  // namespace ca
