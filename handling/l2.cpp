#include <iostream>
#include <stdexcept>

void f3() { throw std::runtime_error("A run time error"); }

void f2() {
  try {
    f3();
  } catch (std::runtime_error &error) {
    std::cout << &error << std::endl;
    throw;
  }
}

void f1() {
  try {
    f2();
  } catch (std::runtime_error &error) {
    std::cout << &error << std::endl;
    throw;
  }
}

int main(int argc, char *argv[]) {
  try {
    f1();
  } catch (std::runtime_error &error) {
    std::cout << &error << std::endl;
  }
  return 0;
}
