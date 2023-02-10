#include <iostream>
using namespace std;

int main() {
  string text;
  cin >> text;
  int text_length = text.size();

  for (int i = 0; i < text_length; i++) {
    if (i != 0 && text[i] != text[i - 1]) {
      cout << " ";
    }
    cout << text[i];
  }
  cout << endl;
  return 0;
}
