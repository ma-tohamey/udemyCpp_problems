#include <iostream>
#include <set>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

// struct employee {
//   int num1, num2;
//   string str;
//
//   employee(int a, int b, string name) { num1 = a, num2 = b, str = name; }
//
//   bool operator<(const employee &rhs) const {
//     return tie(num1, str, num2) < tie(rhs.num1, rhs.str, rhs.num2);
//   }
// };

int main(int argc, char *argv[]) {

  set<int> s1{1, 2, 3, 4, 5};
  int arr;
  vector<int> v{1, 4, 2, 8, 3, 5};
  // unordered_set<int> s2(arr, arr + 3);
  set<int> sorted(v.begin(), v.end());
  for (int val : sorted)
    cout << val << " ";
  cout << endl;
  // set<string> strSet{"ziad", "mostafa", "mostafa", "mostafa", "ali"};
  //
  // for (string name : strSet)
  //   cout << name << " ";
  // cout << endl;
  //
  // if (strSet.count("mostafa"))
  //   cout << "yes" << endl;
  //
  // set<string>::iterator it = strSet.find("mostafa");
  //
  // if (it != strSet.end())
  //   strSet.erase(it);
  //
  // for (string name : strSet)
  //   cout << name << " ";
  // cout << endl;

  return 0;
}
