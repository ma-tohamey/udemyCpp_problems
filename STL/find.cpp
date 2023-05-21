#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string user_text = "(())";
  if (user_text.find(')'))
    user_text.erase();
  cout << user_text << endl;

  return 0;
}
