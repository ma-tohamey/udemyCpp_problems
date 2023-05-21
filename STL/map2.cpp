#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

void print(map<string, tuple<int, string, int>> &mp) {
  for (const pair<string, tuple<int, string, int>> &item : mp)
    // cout << item.first << " - " << item.second << " | ";
    cout << item.first << " " << get<0>(item.second) << " "
         << get<1>(item.second) << " " << get<2>(item.second);
  cout << endl;
}

int main(int argc, char *argv[]) {
  map<string, tuple<int, string, int>> mp;
  mp["mostafa"] = make_tuple(10, "son", 100);
  mp["saad"] = make_tuple(15, "father", 123);
  mp["mostafa"] = make_tuple(10, "idot", 135);
  mp["Mostafa"] = make_tuple(200, "ramy", 140);

  print(mp);

  auto it = mp.find("saad");
  if (it != mp.end())
    cout << "yes i found it" << endl;
  else
    cout << "no i didn't found it" << endl;

  tuple<int, string, int> t{10, "son", 100};

  for (auto item : mp) {
    string cnt_key = item.first;
    if (get<1>(mp[cnt_key]) == "ramy")
      cout << "yes i found ramy with cnt_key: " << cnt_key << endl;
  }
  return 0;
}
