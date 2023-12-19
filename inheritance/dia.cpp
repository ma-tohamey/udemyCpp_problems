#include <iostream>

class A {
public:
  int a;
};

class B : virtual public A {
public:
  // a
  int b;
};

class C : virtual public A {
public:
  // a
  int c;
};

class D : public B, public C {
public:
  // a
  // b
  // c
  int d;
};
int main(int argc, char *argv[]) {
  A objA;
  objA.a = 10; // this will work because your target is clear

  B objB;
  objB.a = 20; // your target is also clear
               // your target is the a variable which inside the
  D objD;
  objD.a = 30;
  return 0;
}
