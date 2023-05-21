#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void print_map(const map<string, int> &mp) {
  for (const pair<string, int> &item : mp)
    cout << item.first << " - " << item.second << "|";
  cout << endl;
}

int main(int argc, char *argv[]) {
  map<string, int> mp;
  mp["mostafa"] = 10;
  mp["Saad"] = 20;
  mp["mostafa"] = 30;
  mp["Mostafa"] = 40;

  print_map(mp);

  map<char, vector<int>> my_data;

  vector<int> x;
  x.push_back(1);
  x.push_back(2);
  x.push_back(3);

  for (auto num : x)
    cout << num << " ";
  cout << endl;

  my_data['A'] = x;
  x.push_back(4);

  //
  for (int i = 0; i != my_data['A'].size(); i++)
    cout << my_data['A'][i] << " ";
  cout << endl;
  //

  for (auto num : x)
    cout << num << " ";
  cout << endl;
  return 0;
}
