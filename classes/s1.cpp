
// CPP program to illustrate
// class objects as static
#include <iostream>
using namespace std;

class GfG {

public:
  static int i;
  GfG() {
    i = 0;
    // cout << "Inside Constructor\n";
  }

  // ~GfG() { cout << "Inside Destructor\n"; }
};

int GfG::i = 10;
int main() {
  static int x = 0;
  x = 10;
  cout << x << endl;
  x = 100;
  cout << x << endl;
  static GfG obj;
  obj.i = 1;

  cout << obj.i << endl;

  GfG obj2;
  obj2.i = 15;
  cout << obj2.i << endl;
  // cout << "End of main\n";
}
