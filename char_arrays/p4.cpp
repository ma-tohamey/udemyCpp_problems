#include <iostream>

using namespace std;

int main() {
  string input, prefix, result = "YES";
  cin >> input >> prefix;

  int prefix_length = prefix.size();
  for (int i = 0; i < prefix_length; i++) {
    bool not_prefix = (input[i] != prefix[i]);
    if (not_prefix) {
      result = "NO";
    }
  }
  cout << result << endl;
  return 0;
}
