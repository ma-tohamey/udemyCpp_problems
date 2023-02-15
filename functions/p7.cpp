#include <iostream>
#include <string>
using namespace std;

bool starts_with(string input, string pattern, int pos) {
  bool starts_with = true;
  int pattern_length = pattern.size();

  for (int i = 0; i < pattern_length; i++, pos++) {
    if (input[pos] != pattern[i]) {
      starts_with = false;
      break;
    }
  }
  return starts_with;
};

string replace_str(string input, string pattern, string to) {
  int input_size = input.size();
  string output = "";
  for (int i = 0; i < input_size;) {
    if (starts_with(input, pattern, i)) {
      output += to;
      i += pattern.size();
    } else {
      output += input[i];
      i++;
    }
  }
  return output;
};

int main(int argc, char *argv[]) {
  string text, pattern, sub;
  cin >> text >> pattern >> sub;

  cout << replace_str(text, pattern, sub) << endl;
  return 0;
}
