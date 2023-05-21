#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(int argc, char *argv[]) {
  unordered_set<int> s1{20, 10, 20, 5, 30};

  for (auto num : s1)
    cout << num << " ";
  cout << endl;

  s1.insert(7);
  s1.insert(0);

  for (auto num : s1)
    cout << num << " ";
  cout << endl;
  return 0;
}
