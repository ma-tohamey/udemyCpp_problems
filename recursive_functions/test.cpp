#include <iostream>

using namespace std;

int factorial(int number) {
  if (number > 0) {
    return factorial(number - 1) * number;
  }
  return 1;
};
int main(int argc, char *argv[]) {
  int factorial_number;
  cin >> factorial_number;

  cout << factorial(factorial_number) << endl;
  return 0;
}
