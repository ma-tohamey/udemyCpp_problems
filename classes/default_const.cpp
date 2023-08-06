#include <iostream>

class A {
public:
  A() {
    std::cout << "a constructor" << std::endl;
  } // user defiend constructor // understood with no problem
  int i;
  std::string s;
};

class B {
public:
  // in this class there is no user defiend constructor
  // so the compiler will generate a default constructor
  //
  // understood with no problems
  int i;
  std::string s;
};

class C {
public:
  // in this class there is no user defiend constructor
  C() = default; // i just assign the constructor to the default constructor

  // understood with no problem
  int i;
  std::string s;
};

class D {
public:
  D(); // till this line the compiler will say this
       // " ok he separte the defination from the implimintaion
       //   so i am sure that is a user defined constructor"
  int i;
  std::string s;
};

// (compiler see next line) --> "k i will assign the user defined constructor
//                                to the default one"
D::D() = default;

int main(int argc, char *argv[]) {
  for (int i = 0; i < 5; ++i) {
    // default initializtion
    A a1;
    B b1;
    C c1;
    D d1;

    std::cout << a1.i << std::endl;
    std::cout << b1.i << std::endl;
    std::cout << c1.i << std::endl;
    std::cout << d1.i << std::endl;

    // value initializtion
    A a2{};
    B b2{};
    C c2{};
    D d2{};

    std::cout << a2.i << std::endl;
    std::cout << b2.i << std::endl;
    std::cout << c2.i << std::endl;
    std::cout << d2.i << std::endl;

    int mahmoud;
    std::cout << mahmoud << std::endl;
  }
  return 0;
}
