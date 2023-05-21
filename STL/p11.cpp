#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[]) {
  string user_input, result;
  cin >> user_input;

  stack<char> s;
  for (int i = user_input.size(); i >= 0; i--) {
    if (!s.empty() && s.top() == user_input[i]) {
      s.pop();
      continue;
    }
    s.push(user_input[i]);
  }
  while (!s.empty())
    result += s.top(), s.pop();

  cout << result << endl;

  // for (auto it = user_input.begin(); it != user_input.end();) {
  //   if (!s.empty() && s.top() == *it) {
  //     s.pop();
  //     user_input.erase(it--);
  //     user_input.erase(it);
  //     continue;
  //   }
  //   s.push(*it);
  //   it++;
  // }
  // cout << user_input << endl;
  return 0;
}
