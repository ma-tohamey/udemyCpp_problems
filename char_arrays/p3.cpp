#include <iostream>

using namespace std;

int main() {
  string to_letter = "YAIMNESTODUAPWXHQFBRJKCGVL";
  string to_symbol = "!@#$%^&*()";

  string word;
  cin >> word;
  int word_length = word.size();

  for (int i = 0; i < word_length; i++) {
    char current_letter = word[i];
    bool is_lower = current_letter >= 'a' && current_letter <= 'z';
    bool is_digit = current_letter >= '0' && current_letter <= '9';

    if (is_lower) {
      word[i] = to_letter[current_letter - 'a'];
    }
    if (is_digit) {
      word[i] = to_symbol[current_letter - '0'];
    }
  }
  cout << word << endl;
  return 0;
}
