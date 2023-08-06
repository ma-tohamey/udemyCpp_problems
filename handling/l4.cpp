#include <iostream>
#include <vector>

int my_abs(int x) noexcept {
  throw 2;
  if (x < 0)
    return -x;
  return x;
}

int my_abs_div(int x, int y) { return my_abs(x) / my_abs(y); }

// int my_abs_div(int x, int y) noexcept(noexcept(my_abs(y))) {
//   return my_abs(x) / my_abs(y);
// }

// template <typename T> T make_copy(T const &src) noexcept(noexcept(T(src))) {
//   return src;
// }

int main(int argc, char *argv[]) {
  std::cout << noexcept(my_abs(10)) << std::endl;
  try {
    std::cout << my_abs_div(6, 2) << std::endl;
  } catch (...) {
    std::cout << "Caught" << std::endl;
  }
  std::cout << "bye" << std::endl;

  // std::cout << noexcept(my_abs(0)) << std::endl;
  // std::cout << noexcept(my_abs_div(0, 0)) << std::endl;
  // std::cout << noexcept(make_copy(std::vector<int>())) << std::endl;
  //
  // try {
  //   std::cout << my_abs_div(6, 2) << std::endl;
  // } catch (...) {
  // }
  // std::cout << "bye" << std::endl;
  return 0;
}
