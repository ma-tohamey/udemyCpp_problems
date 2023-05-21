#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
  map<string, set<string>> names_mp;

  int cases;
  cin >> cases;
  while (cases--) {
    string name, cnt_chars;
    cin >> name;
    for (char c : name) {
      cnt_chars += c;
      names_mp[cnt_chars].insert(name);
    }
  }

  int quries;
  cin >> quries;
  while (quries--) {
    string query;
    cin >> query;
    for (string name : names_mp[query])
      cout << name << ' ';
    cout << endl;
  }
  return 0;
}
