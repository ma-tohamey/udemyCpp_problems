#include <iostream>
#include <map>
#include <stack>

using namespace std;

bool valid_parentheses(string user_input) {
  map<char, char> mp;
  mp['{'] = '}';
  mp['('] = ')';
  mp['['] = ']';

  stack<char> s;

  if (user_input.size() % 2 != 0)
    return false;

  for (char c : user_input) {
    // if it is an opening par
    if (mp.count(c))
      s.push(c);
    // if it a closing par
    else {
      if (mp[s.top()] == c)
        s.pop();
      else
        break;
    }
  }
  return s.empty();
}

int main(int argc, char *argv[]) {
  string user_input;
  cin >> user_input;

  if (valid_parentheses(user_input))
    cout << "Valid" << endl;
  else
    cout << "Invalid" << endl;
  return 0;
}
