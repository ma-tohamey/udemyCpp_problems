#include <iostream>
#include <stack>

using namespace std;

int score_of_parentheses(string &user_paren) {
  stack<int> s;
  s.push(0);

  for (char c : user_paren) {
    if (c == '(')
      s.push(0);
    else {
      int last_par = s.top();
      s.pop();
      if (last_par == 0)
        last_par += 1;
      else
        last_par *= 2;

      int new_val = s.top() + last_par;
      s.pop();
      s.push(new_val);
    }
  }
  return s.top();
}

int main(int argc, char *argv[]) {
  string user_paren;
  cin >> user_paren;

  cout << score_of_parentheses(user_paren) << endl;

  return 0;
}
