#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

  // in every row make 5 cols with a value of 1
  vector<int> row(5, 1);
  // make 3 rows of my custom row
  vector<vector<int>> v2d(3, row);

  for (auto row : v2d) {
    for (auto col : row)
      cout << col << " ";
    cout << endl;
  }
  cout << endl;

  // vector<int> v{3, -4, 7, -2, -1, 3, -5, 10, 3};

  // for (auto it = v.begin(); it != v.end();)
  //   if (*it < 0)
  //     it = v.erase(it);
  //   else
  //     it++;

  // vector<int> s{1, 2, 3, 4, 5};
  // auto it = find(v.begin(), v.end(), -4);
  // if (it != v.end())
  //   v.insert(it, s.begin(), s.end());

  // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  //   cout << *it << " ";

  // for (int val : v)
  //   cout << val << " ";

  return 0;
}
