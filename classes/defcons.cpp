#include <iostream>

class A {
public:
  A() {}
  int i;
  std::string s;
};

class B {
public:
  int i;
  std::string s;
};

class C {
public:
  C() = default;
  int i;
  std::string s;
};

class D {
public:
  D();
  int i;
  std::string s;
};

D::D() = default;

int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; ++i) {
    A a1;
    B b1;
    C c1;
    D d1;

    std::cout << a1.i << std::endl;
    std::cout << b1.i << std::endl;
    std::cout << c1.i << std::endl;
    std::cout << d1.i << std::endl;

    A a2{};
    B b2{};
    C c2{};
    D d2{};

    std::cout << a2.i << std::endl;
    std::cout << b2.i << std::endl;
    std::cout << c2.i << std::endl;
    std::cout << d2.i << std::endl;
  }
  return 0;
}
