#include <iostream>

class MyNumber {
private:
  int *val1;
  int val2;

public:
  MyNumber(int x = 3, int y = 5) {
    val1 = new int;
    *val1 = x;
    val2 = y;
  }

  MyNumber(const MyNumber &other) {
    val1 = new int;
    *val1 = *other.val1;
    val2 = other.val2;
  }

  ~MyNumber() { delete val1; }

  void PrintValueAndAddress() {
    std::cout << "val1: " << *val1 << ' ' << val1 << std::endl;
    std::cout << "val2: " << val2 << ' ' << &val2 << std::endl << std::endl;
  }
};

// void fun1(MyNumber x) {}
//
// MyNumber fun2() {
//   MyNumber e(1, 2);
//   return e;
// }
//
void play1(MyNumber a) {}
void play2(MyNumber &a) {}
void play3(const MyNumber &a) {}

MyNumber play4() {
  MyNumber x(1, 1);
  return x;
}

int main(int argc, char *argv[]) {

  // play1(MyNumber());
  // play2(MyNumber());
  // play3(MyNumber());

  // MyNumber a;
  // MyNumber b(a);
  // MyNumber b = a;
  // MyNumber b(10, 20);

  // MyNumber c(b);
  // MyNumber d = b;
  //
  // fun1(c);
  // fun2();
  //
  // a = b;
  // b = a;

  // a.PrintValueAndAddress();
  // b.PrintValueAndAddress();
  // b = a;
  // b.PrintValueAndAddress();
  // c.PrintValueAndAddress();
  // d.PrintValueAndAddress();
  return 0;
}
