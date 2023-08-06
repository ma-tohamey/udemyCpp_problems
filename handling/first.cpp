#include <cstddef>
#include <iostream>
#include <stdexcept>

int *CreateArrayOnMobile(int len) {
  if (len <= 0)
    throw 17;
  // throw std::invalid_argument(
  // "Array length Value can't be negative or zero!");

  if (len >= 10000)
    throw 18;
  // throw std::runtime_error("Too big array for this mobile memory");

  return new int[len];
}

int main(int argc, char *argv[]) {
  int *p = nullptr;
  try {
    int *p = CreateArrayOnMobile(0000);
  } catch (std::runtime_error &error) {
    std::cout << error.what() << std::endl;
  } catch (std::invalid_argument &error) {
    std::cout << error.what() << std::endl;
  } catch (int &error_num) {
    std::cout << "Error Code is: " << error_num << std::endl;
  } catch (...) {
    std::cout << "Caught unknown exception type!" << std::endl;
  }

  if (p != nullptr) {
    delete[] p;
    p = nullptr;
  }
  return 0;
}
