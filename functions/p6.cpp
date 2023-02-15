#include <iostream>

using namespace std;

bool is_prime(int num) {
  bool is_prime = true;
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      is_prime = false;
    }
  }
  return is_prime;
};

int nth_prime(int n) {
  int current_number = 2;
  while (n) {
    if (is_prime(current_number)) {
      n--;
    }
    current_number++;
  }
  return current_number - 1;
};

int main(int argc, char *argv[]) {
  int number;
  cin >> number;

  cout << nth_prime(number) << endl;
  return 0;
}
