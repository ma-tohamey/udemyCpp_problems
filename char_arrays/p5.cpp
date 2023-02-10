#include <iostream>

using namespace std;

int main() {
  string input, suffix, result = "YES";
  cin >> input >> suffix;

  int suffix_length = suffix.size() - 1;
  int input_length = input.size() - 1;

  for (int i = 0; i < suffix_length; i++) {
    bool not_suffix = (input[input_length--] != suffix[suffix_length--]);
    if (not_suffix) {
      result = "NO";
    }
  }
  cout << result << endl;
  return 0;
}
