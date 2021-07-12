#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <ctime>

namespace utils
{

  class DateTime
  {
  public:
    DateTime();

    ~DateTime();

  public:
    int timestamp();

    int timezone();

    std::string format();

  private:
    time_t now;
  };

} // namespace utils

#endif // DATETIME_H
