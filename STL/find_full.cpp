#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {

  map<string, vector<string>> mp;
  int n_num;
  cin >> n_num;

  for (int i = 0; i < n_num; i++) {

    int num;
    cin >> num;
    string cnt_fname = "";
    vector<string> names;
    string cnt_name;

    for (int j = 0; j < num; j++) {
      cin >> cnt_name;
      if (j)
        cnt_fname += " ";
      cnt_fname += cnt_name;
      // cnt_fname += (j == num - 1) ? cnt_name : cnt_name + ' ';
      names.push_back(cnt_fname);
    }

    for (auto name : names)
      mp[name].push_back(cnt_fname);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int name_len;
    cin >> name_len;

    string query_name, query_fname;
    for (int i = 0; i < name_len; i++) {
      cin >> query_name;
      if (i)
        query_fname += ' ';
      query_fname += query_name;
      // query_fname += (i == name_len - 1) ? query_name : query_name + ' ';
    }

    cout << "\nSearch Result..." << endl;
    for (auto fname : mp[query_fname])
      cout << fname << " | ";
    cout << endl;
  }
  return 0;
}
