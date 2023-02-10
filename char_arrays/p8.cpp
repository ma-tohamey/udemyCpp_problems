#include <iostream>

using namespace std;

int main() {
  string str_number;
  cin >> str_number;
  int str_number_length = str_number.size();

  int number = str_number[0] - '0';
  for (int i = 1; i < str_number_length; i++) {
    int current_digit = str_number[i] - '0';
    number = number * 10 + current_digit;
  }
  cout << number << " " << number * 3 << endl;
  return 0;
}
