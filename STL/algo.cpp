#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  vector<int> v(5);
  for (int i = 0; i != v.size(); i++)
    v[i] = 10 - i;

  // print without sorting
  for (auto val : v)
    cout << val << " ";
  cout << endl;

  // sort the vector
  sort(v.begin(), v.end());

  for (auto val : v)
    cout << val << " ";
  cout << endl;

  // an experment of an array
  int a[5] = {5, 2, 6, 3, 5};
  sort(a, a + 5);
  for (int i = 0; i < 5; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  // sort it in reverse
  sort(v.rbegin(), v.rend());

  for (auto val : v)
    cout << val << " ";
  cout << endl;

  // trying reverse method
  reverse(v.begin(), v.end());

  for (auto val : v)
    cout << val << " ";
  cout << endl;

  return 0;
}
