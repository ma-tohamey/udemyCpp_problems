#include <iostream>
#include <new>

int main(int argc, char *argv[]) {
  long long int sz = 100000000000000000 * 10;
  // int sz = 10;

  // the first way to check if i reserved target memeory size
  try {
    int *ptr1 = new int[sz];
    delete[] ptr1;
    ptr1 = nullptr;
  } catch (std::bad_alloc &error) {
    std::cout << "Failed to allocate memeory " << error.what() << std::endl;
  }

  int *ptr2 = new (std::nothrow) int[sz];
  if (!ptr2)
    std::cout << "Failed!" << std::endl;
  else {
    std::cout << "Succeeded" << std::endl;
    delete[] ptr2;
    ptr2 = nullptr;
  }

  return 0;
}
