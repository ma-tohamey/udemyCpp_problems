#include <iostream>

class A;

class B {
public:
  void AccessA1(A &x);
  void AccessA2(A &x);
};

class A {
private:
  int a1_private = 10;
  int a2_private = 20;

  void HiddenA() { std::cout << "I am hidden" << std::endl; }

public:
  friend void B::AccessA1(A &x);
};
