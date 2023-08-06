#include <iostream>

int my_abs(int x) {
  if (x < 0)
    return -x;
  return x;
}

int my_abs_div(int x, int y) { return my_abs(x) / my_abs(y); }

int main(int argc, char *argv[]) {
  try {
    std::cout << my_abs_div(6, 0) << std::endl;
  } catch (...) {
    std::cout << "oooh" << std::endl;
  }
  std::cout << "bye" << std::endl;
  return 0;
}
