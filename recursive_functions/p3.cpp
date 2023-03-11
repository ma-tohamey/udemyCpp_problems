#include <iostream>
using namespace std;

void print_sequence(int number) {
  cout << number << " ";

  if (number == 1) {
    return;
  }

  bool is_even = (number % 2) == 0;
  if (is_even)
    print_sequence(number / 2);
  else
    print_sequence(3 * number + 1);
}

int main(int argc, char *argv[]) {
  int number;
  cin >> number;
  print_sequence(number);
  cout << endl;
  return 0;
}
