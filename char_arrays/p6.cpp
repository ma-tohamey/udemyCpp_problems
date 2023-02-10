#include <iostream>
using namespace std;

int main() {
  string input, sub_string, result = "YES";
  cin >> input >> sub_string;

  int input_size = input.size();
  int sub_string_size = sub_string.size();

  for (int i = 0; i < input_size; i++) {
    bool is_match = (input[i] == sub_string[0]);
    if (is_match) {

      for (int j = 1; j < sub_string_size; j++) {
        bool not_sub_string = (input[i + j] != sub_string[j]);
        if (not_sub_string) {
          result = "NO";
          break;
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}
