#include <iostream>

class myvector {
private:
  int *arr;
  int len = 100;

public:
  myvector(int len, int default_value = 0) : len(len), arr(new int[len]) {
    for (int i = 0; i < len; ++i)
      arr[i] = default_value;
  }

  ~myvector() { delete[] arr; }

  int get(int pos) { return arr[pos]; }
};

int main(int argc, char *argv[]) {
  myvector v(10, 12345);
  std::cout << v.get(0) << std::endl;
  std::cout << v.get(1) << std::endl;
  std::cout << v.get(3) << std::endl;
  return 0;
}
