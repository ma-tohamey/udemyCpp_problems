#include <iostream>
#include <stack>
#include <sys/types.h>
using namespace std;

int reverse_num(int num) {
  // int reversed_num = 0;
  int cnt_digit;
  stack<int> s;

  while (num > 0) {
    int cnt_digit = num % 10;
    s.push(cnt_digit);
    num /= 10;
  }

  cnt_digit = 1;

  while (!s.empty()) {
    // reversed_num += (s.top() * cnt_digit);
    num += (s.top() * cnt_digit);
    cnt_digit *= 10;
    s.pop();
  }

  // return reversed_num;
  return num;
}

int main(int argc, char *argv[]) {
  int num;
  cin >> num;
  cout << reverse_num(num) << endl;
  return 0;
}
