#include <iostream>
using namespace std;

int main() {
  string text;
  cin >> text;
  text += "@";
  int text_length = text.size(), letter_frequency = 0;

  for (int i = 0; i < text_length; i++) {
    bool letter_changed = i != 0 && (text[i - 1] != text[i]);
    bool not_last_letter = text[i] != '@';

    if (letter_changed) {
      cout << text[i - 1] << letter_frequency;
      if (not_last_letter) {
        cout << "_";
      }
      letter_frequency = 1;
    } else {
      letter_frequency++;
    }
  }
  cout << endl;
  return 0;
}
