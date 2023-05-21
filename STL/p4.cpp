#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, vector<string>> names_mp;

void saving_name() {
  string full_name;
  int name_len;
  cin >> name_len;
  vector<string> quries;
  for (int i = 0; i < name_len; i++) {
    string cnt_name;
    cin >> cnt_name;
    full_name += (i) ? ' ' + cnt_name : cnt_name;
    quries.push_back(full_name);
  }

  for (string q : quries) {
    names_mp[q].push_back(full_name);
  }
}

void print_results() {
  int name_len;
  cin >> name_len;
  string full_query;
  for (int i = 0; i < name_len; i++) {
    string cnt_query;
    cin >> cnt_query;
    full_query += (i) ? ' ' + cnt_query : cnt_query;
  }

  for (int i = 0; i < names_mp[full_query].size(); i++)
    cout << names_mp[full_query][i] << ", ";
  cout << endl;
}

int main(int argc, char *argv[]) {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++)
    saving_name();

  int quries;
  cin >> quries;
  for (int i = 0; i < quries; i++)
    print_results();

  return 0;
}
