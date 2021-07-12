#include "../include/StringConvert.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

typedef unsigned char uchar;
const std::string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; //=

namespace utils
{

  std::string stringToBase64(const std::string &in)
  {
    std::string out;
    int val = 0, valb = -6;

    for (uchar c : in)
    {
      val = (val << 8) + c;
      valb += 8;
      while (valb >= 0)
      {
        out.push_back(b[(val >> valb) & 0x3F]);
        valb -= 6;
      }
    }

    if (valb > -6)
    {
      out.push_back(b[((val << 8) >> (valb + 8)) & 0x3F]);
    }

    while (out.size() % 4)
    {
      out.push_back('=');
    }

    return out;
  }

  std::string base64ToString(const std::string &in)
  {
    std::string out;

    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++)
    {
      T[b[i]] = i;
    }

    int val = 0, valb = -8;
    for (uchar c : in)
    {
      if (T[c] == -1)
      {
        break;
      }

      val = (val << 6) + T[c];
      valb += 6;

      if (valb >= 0)
      {
        out.push_back(char((val >> valb) & 0xFF));
        valb -= 8;
      }
    }

    return out;
  }

  std::string stringToHex(const std::string &in)
  {
    std::stringstream ss;

    for (const auto &item : in)
    {
      ss << std::hex << int(item);
    }

    return ss.str();
  }

} // namespace utils
