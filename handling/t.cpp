#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

  cout << 20 - 30 << endl;

  unsigned int a = 20;
  unsigned int b = 30;

  cout << a - b << endl;

  unsigned int m = 4294967295;
  cout << m - 10 << endl;

  vector<int> v;
  cout << v.size() << endl;

  cout.setf(ios::scientific);
  cout << 23413.21 << endl;

  cout << 20u - 30 << endl;

  return 0;
}
