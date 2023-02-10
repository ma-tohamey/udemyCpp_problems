#include <iostream>

using namespace std;

int main() {
  string input, sub_sequence, result = "NO";
  cin >> input >> sub_sequence;

  int input_length = input.size();
  int sub_sequence_length = sub_sequence.size();

  int sub_sequence_idx = 0;
  for (int i = 0; i < input_length; i++) {
    bool is_sub_sequence = (input[i] == sub_sequence[sub_sequence_idx]);
    if (is_sub_sequence) {
      sub_sequence_idx++;
      bool sub_sequence_end = sub_sequence_idx == sub_sequence_length;
      if (sub_sequence_end) {
        result = "YES";
      }
    }
  }

  cout << result << endl;
  return 0;
}
