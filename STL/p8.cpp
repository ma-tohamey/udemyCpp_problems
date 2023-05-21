#include <iostream>
#include <stack>
using namespace std;

int reverse_num(int num) {
  stack<int> s;
  while (num != 0) {
    s.push(num % 10);
    num /= 10;
  }

  int reversed = 0, cnt_digit = 1;
  while (!s.empty()) {
    reversed += s.top() * cnt_digit;
    s.pop();
    cnt_digit *= 10;
  }
  return reversed;
}

int main(int argc, char *argv[]) {
  int user_int;
  cin >> user_int;

  cout << reverse_num(user_int) << endl;
  return 0;
}
