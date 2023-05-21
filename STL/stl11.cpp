#include <iostream>
#include <stack>

using namespace std;

string remove_duplicates_in_string(string &user_input) {
  string result_str = "";
  stack<char> s;
  for (int i = user_input.size(); i >= 0; i--) {
    if (!s.empty() && user_input[i] == s.top()) {
      s.pop();
      continue;
    }
    s.push(user_input[i]);
  }

  while (!s.empty()) {
    result_str += s.top();
    s.pop();
  }
  return result_str;
}

int main(int argc, char *argv[]) {
  string user_input;
  cin >> user_input;
  cout << remove_duplicates_in_string(user_input) << endl;
  return 0;
}
