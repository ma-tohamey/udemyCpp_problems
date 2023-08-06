#include <iostream>

int my_abs(int x) // noexcept
{
  throw 2;
  if (x < 0)
    return -x;
  return x;
}

int my_abs_div(int x, int y) /*noexcept(true)*/ {
  return my_abs(x) / my_abs(y);
}
int main(int argc, char *argv[]) {
  std::cout << my_abs_div(6, 2) << std::endl;
  std::cout << "bye" << std::endl;
  return 0;
}
