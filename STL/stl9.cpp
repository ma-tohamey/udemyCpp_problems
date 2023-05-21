#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void Entering_names(map<string, vector<string>> &names_map) {
  string name, sub_name = "";
  cin >> name;

  for (char c : name) {
    sub_name += c;
    names_map[sub_name].push_back(name);
  }
}

void Search_by_prefix(map<string, vector<string>> &names_map) {
  string prefix;
  cin >> prefix;

  for (string name : names_map[prefix])
    cout << name << ' ';
  cout << endl;
}

int main(int argc, char *argv[]) {
  int cases;
  cin >> cases;
  map<string, vector<string>> names_map;

  for (int i = 0; i < cases; i++)
    Entering_names(names_map);

  int quries;
  cin >> quries;

  for (int i = 0; i < quries; i++)
    Search_by_prefix(names_map);

  return 0;
}
