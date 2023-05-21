#include <cctype>
#include <deque>
#include <exception>
#include <iostream>
using namespace std;

int count_lowers(const string &str) {
  int cnt = 0;
  for (auto it = str.begin(); it != str.end(); it++) {
    char current_char = *it;

    if (islower(current_char))
      cnt++;
  }

  return cnt;
}
int main(int argc, char *argv[]) {
  string user_text;
  cin >> user_text;
  cout << count_lowers(user_text) << endl;
  return 0;
}

// void print_front(deque<int> &q) {
//   cout << "Queue elements (front): ";
//
//   deque<int>::const_reverse_iterator it = q.crbegin();
//
//   while (it != q.crend()) {
//     cout << *it << " ";
//     it++;
//   }
//   cout << endl;
// }
// int main(int argc, char *argv[]) {
//   deque<int> q{1, 2, 3, 4, 5};
//   print_front(q);
//   return 0;
// }
