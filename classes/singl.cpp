#include <iostream>

class A {
private:
  int a;
  int *ptra = &a;

  static A *ptrA;
  A(){};

public:
  static A *get_instance(const A &other) {
    ptrA = new A();
    return ptrA;
  }
  // static A *(const A &other) { return this; }
};
int main(int argc, char *argv[]) {
  // code

  return 0;
}
