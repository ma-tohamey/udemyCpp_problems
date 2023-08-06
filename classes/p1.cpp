#include <iostream>
using namespace std;

class a {
public:
  a() { cout << "a constructor" << endl; }
  ~a() { cout << "a destructor" << endl; }
};
class b {
public:
  b() { cout << "b constructor" << endl; }
  ~b() { cout << "b destructor" << endl; }
};
class c {
public:
  c() { cout << "c constructor" << endl; }
  ~c() { cout << "c destructor" << endl; }
};

class d {
public:
  a aa;
  b bb;
  c cc;

  d(){};
  d(a aa, b bb, c cc) : bb(bb), aa(aa), cc(cc) {}
  // d(a aa, b bb, c cc) : aa(aa), bb(bb), cc(cc) {}
};

int main(int argc, char *argv[]) {
  d dd;
  return 0;
}
