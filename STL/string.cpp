#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string test = "hi abc abc abc abcbi Mostafa";

  cout << test.substr(3) << endl;
  cout << test.substr(3, 1) << endl;

  cout << test.find("abc") << endl;

  cout << "Mostafa at: " << test.find("Mostafa") << endl;
  cout << "Mostafa at: " << (int)test.find("Mostafa") << endl;

  cout << test.find_last_of("ciab") << endl;
  cout << test.find_first_of("aic") << endl;
  cout << test.find_first_of("aic", 4) << endl;
  cout << test.find_first_not_of("aic") << endl;

  cout << test << endl;
  test.replace(4, 3, "x");
  cout << test << endl;
  test.replace(4, 3, "x");
  cout << test << endl;
  return 0;
}
