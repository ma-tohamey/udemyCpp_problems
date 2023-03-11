#include <iostream>
using namespace std;

int length_3n_plus_1(int number) {
  if (number == 1)
    return 1;

  if (number % 2 == 0)
    return 1 + length_3n_plus_1(number / 2);
  else
    return 1 + length_3n_plus_1(3 * number + 1);
}

int main(int argc, char *argv[]) {
  int number;
  cin >> number;
  cout << length_3n_plus_1(number) << endl;
  return 0;
}
