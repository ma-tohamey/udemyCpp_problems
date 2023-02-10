#include <iostream>
using namespace std;

int main() {
  int letter_frequency[26] = {0};
  string word;

  cin >> word;
  int word_length = word.size();

  for (int i = 0; i < word_length; i++) {
    char current_letter = word[i];
    bool letter_is_lower = current_letter >= 'a' && current_letter <= 'z';
    if (letter_is_lower) {
      int letter_idx = current_letter - 'a';
      letter_frequency[letter_idx]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (letter_frequency[i]) {
      char current_letter = i + 'a';
      cout << current_letter << ' ' << letter_frequency[i] << endl;
    }
  }
  return 0;
}
