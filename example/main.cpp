#include <iostream>
#include <libutils/libutils.h>

int main(int argc, char **argv)
{
  utils::Timer::start();

  auto t = utils::DateTime();
  std::cout << t.timestamp() << std::endl;
  std::cout << t.timezone() << std::endl;
  std::cout << t.format() << std::endl;

  std::cout << utils::stringToBase64("Aa1234567") << std::endl;
  std::cout << utils::stringToHex("Aa1234567") << std::endl;

  utils::Timer::end();

  return EXIT_SUCCESS;
}
