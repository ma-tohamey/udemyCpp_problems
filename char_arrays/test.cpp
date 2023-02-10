#include <iostream>

using namespace std;

int main() {
  // char letter = 'C';
  // letter = letter - 'A' + 'a';
  // cout << letter << endl;

  string name = "Hany";

  int sz = name.size();
  cout << sz << endl;

  for (int i = 0; i < sz; i++) {
    cout << name[i];
  }
  return 0;
}
