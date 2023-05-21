#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print(stack<string> &s) {
  cout << "Stack elements: ";

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  stack<string> s;
  s.push("limona");
  s.push("atef");
  s.push("altohamy");
  s.push("mahmoud");

  print(s);

  return 0;
}
