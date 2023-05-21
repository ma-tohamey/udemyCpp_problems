#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

bool is_valid_str(string str) {
  map<char, char> mp;
  mp[')'] = '(';
  mp['}'] = '{';
  mp[']'] = '[';

  stack<char> parenthaeses;

  for (char ch : str) {
    if (mp.count(ch)) {
      if (parenthaeses.empty())
        return false;

      char open = parenthaeses.top();
      if (mp[ch] != open)
        return false;

      parenthaeses.pop();
    } else
      parenthaeses.push(ch);
  }
  return parenthaeses.empty();
}

int main(int argc, char *argv[]) {
  string user_text;
  cin >> user_text;

  if (is_valid_str(user_text))
    cout << "Valid String" << endl;
  else
    cout << "Invalid String" << endl;
  return 0;
}
