#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_2d_vector(vector<vector<int>> &v2d) {
  for (auto row : v2d) {
    for (auto col : row)
      cout << col << " ";
    cout << endl;
  }
}

int main(int argc, char *argv[]) {
  vector<int> cols(5, 1);
  vector<vector<int>> v2d(3, cols);

  // print_2d_vector(v2d);

  v2d[0][0] = 9;
  v2d[1].push_back(5);
  v2d[1].push_back(6);
  v2d[2].erase(v2d[2].begin());

  print_2d_vector(v2d);

  // for (auto &col : cols)
  //   cout << col << " ";
  // cout << endl;

  return 0;
}
//   vector<int> v{3, -4, 7, -2, -1, 3, -5, 10, 3};
//
//   auto it = find(v.begin(), v.end(), -2);
//
//   cout << *it << endl;
//
//   if (it != v.end()) {
//     vector<int> v2{8, 9, 10};
//     v.insert(it, v2.begin(), v2.end());
//   }
//
//   for (auto &val : v)
//     cout << val << " ";
//   cout << endl;
//
//   return 0;
// }
// int main(int argc, char *argv[]) {
//   vector<int> v{3, -4, 7, -2, -1, 3, -5, 10, 3};
//
//   for (auto it = v.begin(); it != v.end();) {
//     if (*it < 0)
//       // v.erase(it);
//       it = v.erase(it);
//     else
//       it++;
//   }
//
//   for (auto &val : v)
//     cout << val << ' ';
//   cout << endl;
//   return 0;
// }

// int main(int argc, char *argv[]) {
//   vector<int> v1;
//
//   for (auto num : v1)
//     cout << num << " ";
//   cout << endl;
//
//   v1.push_back(30);
//   v1.push_back(10);
//   v1.push_back(20);
//
//   for (auto num : v1)
//     cout << num << " ";
//   cout << endl;
//
//   for (int i = 0; i < v1.size(); i++)
//     cout << v1[i] << " ";
//   cout << endl;
//
//   vector<int> v2(5, 7);
//
//   for (auto num : v2)
//     cout << num << " ";
//   cout << endl;
//   return 0;
// }
