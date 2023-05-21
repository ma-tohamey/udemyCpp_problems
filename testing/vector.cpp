#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  vector<int> v(5);

  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
    v.push_back();
  }
  return 0;
}
