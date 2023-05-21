#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

// bool is_valid_par(string &user_text) { // this function will validate without
// order
//   map<char, char> mp;
//   mp['('] = ')';
//   mp['{'] = '}';
//   mp['['] = ']';
//
//   while (!user_text.empty()) {
//     auto it_begin = user_text.begin();
//     auto it_target = find(user_text.begin(), user_text.end(), mp[*it_begin]);
//     if (it_target != user_text.end()) {
//       it_begin = user_text.erase(it_begin);
//       // chatgpt fix my code by subtracting 1 from it_target
//       it_target = user_text.erase(it_target - 1);
//     } else
//       return 0;
//   }
//
//   return user_text.empty();
// }

bool is_valid_par(string &user_text) { // this function will validate with order
  map<char, char> mp;
  mp['('] = ')';
  mp['{'] = '}';
  mp['['] = ']';

  stack<char> opening_pars;

  bool is_valid = true;
  for (char c : user_text) {
    if (mp[c]) {
      opening_pars.push(c);
      continue;
    }
    if (opening_pars.size() > 0 && mp[opening_pars.top()] == c) {
      opening_pars.pop();
    } else {
      is_valid = false;
      break;
    }
  }
  return is_valid;
}
int main(int argc, char *argv[]) {

  string user_text;
  cin >> user_text;
  if (is_valid_par(user_text))
    cout << "Valid" << endl;
  else
    cout << "Invalid" << endl;

  return 0;
}
