#include <iostream>
#include <utility>
using namespace std;

// struct Employee {
//   string name;
//   int salary;
// };

int main(int argc, char *argv[]) {

  // pair<int, string> p{33, "mahmoud"};
  // auto p = pair(33, "mostafa");
  // pair p(33, "ramy");
  //
  int year = 2023;
  string name = "mahmoud";
  pair p(1010, "ahmed tawfik");

  cout << p.first << ' ' << p.second << endl;

  auto &[y, n] = p;
  cout << y << ' ' << n << endl;

  cout << p.first << ' ' << p.second << endl;

  // Employee emp{"mostafa", 20};
  //
  // auto [str1, sal1] = emp;
  // cout << "emp name: " << str1 << " emp sal: " << sal1 << endl;

  // int arr[]{2, 3, 5, 7};
  // auto [a1, b1, c1, d1] = arr;
  //
  // cout << c1 << endl;
  // c1 += 20;
  // cout << c1 << endl;
  // cout << arr[2] << endl;
  //
  // auto &[a2, b2, c2, d2] = arr;
  //
  // cout << "c2: " << c2 << endl;
  // c2 += 20;
  // cout << c2 << endl;
  // cout << arr[2] << endl;

  // auto &[a2, b2, c2, d2] = arr;
  // cout << c1 << endl;
  // c1 += 20;
  // cout << c1 << endl;
  // cout << arr[2] << endl;

  return 0;
}
