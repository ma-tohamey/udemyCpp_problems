#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, vector<string>> name_map;

void name_input() {
  int name_leng;
  cin >> name_leng;
  string name, full_name;

  // for to get full name
  vector<string> sub_names;
  for (int i = 0; i < name_leng; i++) {
    cin >> name;
    full_name += (i) ? ' ' + name : name;
    sub_names.push_back(full_name);
  }

  for (string sub_name : sub_names) {
    name_map[sub_name].push_back(full_name);
  }
  sub_names.clear();
}

void name_search() {
  int name_leng;
  cin >> name_leng;
  string name, query_name;
  for (int i = 0; i < name_leng; i++) {
    cin >> name;
    query_name += (i != 0) ? ' ' + name : name;
  }

  int found_results = name_map[query_name].size();
  if (name_map.count(query_name)) {
    cout << "******************** Found Results **********************" << endl;
    for (string full_name : name_map[query_name])
      cout << full_name << endl;
    cout << "*********************************************************" << endl;
  } else {
    cout << "No such sub-full name" << endl;
  }
};

int main(int argc, char *argv[]) {
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    name_input();
  }

  int queries;
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    name_search();
  }
  return 0;
}
