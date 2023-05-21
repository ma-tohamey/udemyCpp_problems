#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void print_mset(multiset<string> &mulset) {
  for (auto element : mulset)
    cout << element << " ";
  cout << endl;
}

int main(int argc, char *argv[]) {
  multiset<string> mlset;
  mlset.insert("ziad");
  mlset.insert("mostafa");
  mlset.insert("mostafa");
  mlset.insert("mostafa");
  mlset.insert("ali");

  print_mset(mlset);
  return 0;
}
