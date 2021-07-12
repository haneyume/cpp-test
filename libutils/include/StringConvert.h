#ifndef STRINGCONVERT_H
#define STRINGCONVERT_H

#include <string>

namespace utils
{

  std::string stringToBase64(const std::string &in);

  std::string base64ToString(const std::string &in);

  std::string stringToHex(const std::string &in);

} // namespace utils

#endif // STRINGCONVERT_H
