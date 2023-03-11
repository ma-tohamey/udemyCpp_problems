#include <iostream>
using namespace std;

void print_triangle(int level) {
  if (level == 0)
    return;
  print_triangle(level - 1);
  for (int i = 0; i < level; i++)
    cout << "*";
  cout << endl;
}

int main(int argc, char *argv[]) {
  int number;
  cin >> number;
  print_triangle(number);
  return 0;
}
