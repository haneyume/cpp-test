#include "../include/Timer.h"
#include <iostream>

namespace utils
{

  std::chrono::system_clock::time_point Timer::startTime;

  std::chrono::system_clock::time_point Timer::endTime;

  void Timer::start()
  {
    startTime = std::chrono::system_clock::now();
  }

  void Timer::end()
  {
    endTime = std::chrono::system_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    auto durationValue = static_cast<int>(duration.count());

    std::cout << "Elapsed time: " << durationValue << " microseconds" << std::endl;
  }

} // namespace utils
