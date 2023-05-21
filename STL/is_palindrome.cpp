#include <deque>
#include <iostream>
#include <string>
using namespace std;

bool is_palidrome(string user_text) {
  deque<char> dq;
  for (char c : user_text)
    dq.push_back(c);

  while (dq.size() > 1) {
    if (dq.front() != dq.back())
      return false;
    dq.pop_front();
    dq.pop_back();
  }
  return true;
}

int main(int argc, char *argv[]) {
  string user_text;
  cin >> user_text;

  cout << boolalpha;
  cout << is_palidrome(user_text) << endl;
  return 0;
}
