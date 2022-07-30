#include "timer.h"

namespace ca {

Timer::Timer() { begin_ = std::chrono::high_resolution_clock::now(); }

void Timer::Start() { begin_ = std::chrono::high_resolution_clock::now(); }

double Timer::Time() const {
    duration diff = std::chrono::high_resolution_clock::now() - begin_;
    diff = std::chrono::duration_cast<std::chrono::milliseconds>(diff);

    return diff.count();
}

}  // namespace ca
