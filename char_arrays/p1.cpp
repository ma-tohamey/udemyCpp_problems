#include <iostream>
#include <string>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int sz1 = S.size(), sz2 = T.size();

  int max_size = sz1;
  if (sz2 > max_size) {
    max_size = sz2;
  }

  for (int i = 0; i < max_size; i++) {
    if (i < sz1) {
      cout << S[i];
    }
    if (i < sz2) {
      cout << T[i];
    }
  }
  cout << endl;
  return 0;
}
