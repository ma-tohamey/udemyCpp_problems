#include <iostream>
#include <stdexcept>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> v(10);

  int t = v[25];
  // std::cout << t << std::endl;
  //
  t = v.at(20);
  std::cout << "bye" << std::endl;
  //
  // int max_size = 10;
  // int user_size;
  // std::cin >> user_size;
  //
  // if (user_size >= max_size)
  //   // throw std::range_error("user size is heigher than max_size");
  //   throw std::out_of_range("user size is heigher than max_size");
  return 0;
}
