#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  map<string, vector<string>> names_mp;
  int cases;
  cin >> cases;

  while (cases--) {
    string name, cnt_chars;
    cin >> name;
    for (char c : name) {
      cnt_chars += c;
      names_mp[cnt_chars].push_back(name);
    }
  }

  int quries;
  cin >> quries;
  while (quries--) {
    string query;
    cin >> query;
    for (auto name : names_mp[query])
      cout << name << ' ';
    cout << endl;
  }
  return 0;
}
