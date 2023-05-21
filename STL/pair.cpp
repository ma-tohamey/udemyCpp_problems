#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
  pair<int, string> p = make_pair(10, "mahmoud");
  cout << p.first << " " << p.second << endl;

  pair<pair<string, string>, pair<string, string>> new_p;
  new_p.first = make_pair("one", "two");
  new_p.second = make_pair("three", "four");

  stack<pair<int, string>> s;
  s.push(p);

  cout << new_p.second.first << " " << new_p.first.second << " "
       << new_p.second.second << " " << new_p.first.first << " let's go..."
       << endl;
  return 0;
}
