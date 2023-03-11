#include <iostream>
using namespace std;

bool is_prime(int number, int start_num = 2) {
  if (number <= 1)
    return false;

  if (start_num == number)
    return true;

  if (number % start_num == 0)
    return false;

  return is_prime(number, start_num + 1);
}

int count_primes(int start, int end) {
  if (start > end)
    return 0;

  // // udemy solution
  // int result = count_primes(start + 1, end);

  // this solution is more efficent
  // but it can't handle big numbers like 500000 it's limit is 0 130972
  if (is_prime(start))
    return 1 + count_primes(start + 1, end);
  return 0 + count_primes(start + 1, end);

  // // udemy solution
  // if (is_prime(start))
  //   result += 1;
  // return result;
}
int main(int argc, char *argv[]) {
  int start_num, end_num;
  cin >> start_num >> end_num;

  cout << count_primes(start_num, end_num) << endl;
  return 0;
}
