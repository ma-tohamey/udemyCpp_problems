#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

void print_set(set<string> &st) {
  for (auto val : st)
    cout << val << " ";
  cout << endl;
}

int main(int argc, char *argv[]) {
  set<string> st{"mahmoud", "altohamey", "mahmoud", "atef", "limona"};

  cout << st.count("mahmoud") << endl;

  print_set(st);

  set<string> strSet;
  strSet.insert("ahmed");
  strSet.insert("ali");
  strSet.insert("ali");
  strSet.insert("ali");
  strSet.insert("ramy");
  strSet.insert("Gomaa");
  strSet.insert("ali");
  strSet.insert("ali");
  print_set(strSet);

  auto it = strSet.find("Gomaa");
  cout << strSet.erase(*it) << endl;
  print_set(strSet);

  // string str = "Ilayathapathy";
  // string subStr = "thalapathy";
  // auto it2 = str.find(subStr);
  // cout << it2 - str.begin() << endl;

  cout << strSet.count("ali") << endl;
  return 0;
}
