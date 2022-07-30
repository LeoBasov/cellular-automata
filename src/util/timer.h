#pragma once

#include <chrono>

namespace ca {

using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;
using duration = std::chrono::duration<double>;

class Timer {
   public:
    Timer();

    void Start();
    double Time() const;

   private:
    time_point begin_;
};

}  // namespace ca
