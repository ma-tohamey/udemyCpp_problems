#include <iostream>
using namespace std;

void print_triangle(int number) {
  if (number == 0)
    return;
  for (int i = 0; i < number; i++)
    cout << "*";
  cout << endl;
  print_triangle(number - 1);
}

int main(int argc, char *argv[]) {
  int number;
  cin >> number;
  print_triangle(number);
  return 0;
}
