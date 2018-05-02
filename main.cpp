#include "ComputePhi.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    return 0;
  }
  int number;
  try
  {
    number = std::stoi(argv[1]);
  }
  catch (...)
  {
    return 0;
  }
  std::cout << number << std::endl;
  std::cout << phi::computeDigit(number+1);

  return 0;
}
