#include <iostream>
#include <ostream>

using namespace std;

class ClassA {
public:
  ClassA() {
    cout << "ClassA Constructor" << endl;
    cout << this << endl;
  }
};

class ClassB {
private:
  ClassA aa;
  int x;

public:
  ClassB(int x) /*: aa(ClassA()), x(x)*/ {
    cout << "this is classB const class A ";
    this->aa = ClassA();
    this->x = x;
  }

  ClassB add(const ClassB &other) const { return ClassB(x + other.x); }
  ClassB multi(const ClassB &other) const { return ClassB(x * other.x); }
  ClassB divion(const ClassB &other) const { return ClassB(x / other.x); }

  ClassB operator+(const ClassB &other) const { return add(other); }
};

class ClassC {
private:
  int &y;
  ClassB bb;

public:
  ClassC(int &y, const ClassB &bb) : y(y), bb(bb) {}
};

int main(int argc, char *argv[]) {
  int hello = 10;
  ClassB b1(5);
  ClassB b2(10);
  ClassB result = b1 + b2;
  // ClassC cc(hello, b);
  return 0;
}
