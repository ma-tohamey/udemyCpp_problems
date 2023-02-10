#include<iostream>

using namespace std;

int main()
{
  int n1, n2;
  char operation;

  cin >> n1 >> operation >> n2;

  if (operation == "+")
    cout << n1 + n2 << endl;
  else if (operation == "-")
    cout << n1 - n2 << endl;
  else if (operation == "/")
    cout << n1 / n2 << endl;
  else if (operation == "*")
    cout << n1 * n2 << endl;
  else
    cout << "please make sure to enter (number 1) (operation) (number 2)" << endl;

  return 0;
}
