#include <iostream>

class A {
public:
  // static int i = 10;

  int get_number() {
    static int j = 0;
    j++;
    return j;
  }
};

// int A::i = 12;
int main(int argc, char *argv[]) {
  // some code

  A a;

  std::cout << a.get_number() << std::endl;
  std::cout << a.get_number() << std::endl;
  std::cout << a.get_number() << std::endl;

  A a2;
  std::cout << a2.get_number() << std::endl;
  std::cout << a2.get_number() << std::endl;
  std::cout << a2.get_number() << std::endl;

  return 0;
}
