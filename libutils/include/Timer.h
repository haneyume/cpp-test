#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace utils
{

  class Timer
  {
  public:
    static void start();

    static void end();

  private:
    static std::chrono::system_clock::time_point startTime;

    static std::chrono::system_clock::time_point endTime;
  };

} // namespace utils

#endif // TIMER_H
