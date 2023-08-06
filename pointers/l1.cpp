#include <iostream>
#include <vector>

const std::vector<int> *gov(const std::vector<int> *ptr) {
  ptr = 0;
  std::cout << ptr << std::endl;
  return ptr;
}
const int *goa(const int *ptr) {
  ptr = 0;
  std::cout << ptr << std::endl;
  return ptr;
}
int main(int argc, char *argv[]) {
  std::vector<int> v{5, 7, 8};
  int int_arr[]{5, 7, 8};

  std::cout << &v << ' ' << int_arr << std::endl;
  std::cout << std::endl;
  v = *gov(&v);
  // int_arr = goa(int_arr);

  for (auto x : v)
    std::cout << x << ' ';
  std::cout << std::endl;

  for (auto x : int_arr)
    std::cout << x << ' ';
  std::cout << std::endl;
  return 0;
}
