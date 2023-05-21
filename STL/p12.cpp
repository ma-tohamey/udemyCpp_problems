#include <iostream>
#include <stack>

using namespace std;

int score_of_parenthese(string user_input) {
  stack<int> s;
  for (char c : user_input) {
    if (c == '(')
      s.push(0);

    else {
      int last_val = s.top();
      s.pop();
      if (last_val == 0) {
        last_val += 1;

      } else {
        last_val *= 2;
      }
      int new_val = s.top() + last_val;
      s.pop();
      s.push(new_val);
    }
  }

  // for (char c : user_input) {
  //   if (c == '(')
  //     s.push(0);
  //
  //   else {
  //     if (s.top() == 0) {
  //       s.top() = 1;
  //
  //     } else {
  //       int n = s.top() * 2;
  //       s.pop();
  //       s.top() = n;
  //     }
  //
  //     int sum = 0;
  //     while (!s.empty() && s.top()) {
  //       sum += s.top();
  //       s.pop();
  //     }
  //     s.push(sum);
  //   }
  // }

  return s.top();
}

int main(int argc, char *argv[]) {
  string user_input;
  cin >> user_input;

  cout << score_of_parenthese(user_input) << endl;
  return 0;
}
