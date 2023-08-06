#include <ios>
#include <iostream>
#include <limits>

template <class type1, class type2> void Read2Numbers() {
  type1 x;
  type2 y;
  while (true) {
    std::cin >> x >> y;

    if (std::cin.fail()) {
      std::cout << "Somethin went wrong in input. Try again: ";
      std::cout << std::cin.rdstate()
                << std::endl; // will give me 4 which is error code
      std::cin.clear(); // to remove the error flag from cin to recheck cin.fail
                        // cin.clear() to make cin usable again
      std::cout << std::cin.rdstate()
                << std::endl; // will give me 4 which is error code
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      break;
    }
  }
  std::cout << x << ' ' << y << std::endl;
}

int main(int argc, char *argv[]) {
  int a, b;
  // Read2Numbers<class type1, class type2>();
  std::cout << a << ' ' << b << std::endl;
  return 0;
}
