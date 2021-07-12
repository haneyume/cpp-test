#include "../include/DateTime.h"
#include <sstream>

namespace utils
{

  DateTime::DateTime()
  {
    now = time(nullptr);
  }

  DateTime::~DateTime()
  {
  }

  int DateTime::timestamp()
  {
    return now;
  }

  int DateTime::timezone()
  {
    return 0;
  }

  std::string DateTime::format()
  {
    tm *ltm = localtime(&now);

    int year = ltm->tm_year + 1900;
    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;

    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int second = ltm->tm_sec;

    std::stringstream ss;
    ss << year << "-" << month << "-" << day;
    ss << " ";
    ss << hour << ":" << minute << ":" << second;

    return ss.str();
  }

} // namespace utils
