#include <iostream>
#include <string>

using namespace std;

void read_array(int array[], int length) {
  for (int i = 0; i < length; i++) {
    cin >> array[i];
  }
};

bool is_palindrome(int array[], int length) {
  bool is_palindrome = true;
  for (int i = 0; i < length / 2; i++) {
    if (array[i] != array[length - i - 1]) {
      is_palindrome = false;
    }
  }
  return is_palindrome;
};

int main(int argc, char *argv[]) {
  int array[100];
  int length;
  cin >> length;
  read_array(array, length);

  if (is_palindrome(array, length)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
