#include <iostream>
using namespace std;

int my_pow(int value, int power = 2) {

  // if (power == 0)
  //   return 1;
  // else if (power == 1)
  //   return value;
  // return value * my_pow(value, power - 1);

  if (power == 0)
    return 1;
  return value * my_pow(value, power - 1);
}
int main(int argc, char *argv[]) {
  int value, power;
  cin >> value >> power;
  cout << my_pow(value, power) << endl;
  return 0;
}
