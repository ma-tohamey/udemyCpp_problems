#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  vector<int> v{1, 2, 3, 4, 5, 6};
  auto first_it = v.begin();
  auto second_it = first_it + 1;

  while (second_it != v.end()) {
    cout << *second_it << ' ';
    v.erase(second_it);
  }
  cout << endl;

  return 0;
}
