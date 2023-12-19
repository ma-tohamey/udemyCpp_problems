#include <iostream>

class A {
public:
  virtual ~A() {}
};

class B : public A {};
class C : public A {};

class D {};

void static_cast_test() {
  A *a_from_b = new B();
  B *b = static_cast<B *>(a_from_b);

  C *c = static_cast<C *>(a_from_b);

  // D *d = static_cast<D *>(a_from_b);
}
