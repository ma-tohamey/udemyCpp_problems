#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  int x;
  int &y1 = x;
  int &y2 = y1;

  cout << &x << ' ' << &y1 << ' ' << &y2 << endl;

  // vector<int> vec{1, 2, 3, 4};
  //
  // for (auto val : vec)
  //   cout << val + 1 << ' ';
  // cout << endl;
  //
  // for (auto &val : vec) {
  //   cout << val << ' ';
  //   val = 1;
  // }
  // cout << endl;
  //
  // for (auto const &val : vec)
  //   cout << val << ' ';
  // cout << endl;
  return 0;
}
