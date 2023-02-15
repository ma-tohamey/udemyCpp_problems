#include <iostream>
#include <string>
using namespace std;

string reverse_str(const string &str) {
  int str_size = str.size();
  char reversed_str[str_size];
  str_size--;
  for (int i = str_size; i >= 0; i--) {
    reversed_str[str_size - i] = str[i];
  }
  reversed_str[str_size + 1] = '\0';
  return reversed_str;
};
int main(int argc, char *argv[]) {
  string line;
  getline(cin, line);

  cout << reverse_str(line) << endl;

  return 0;
}
