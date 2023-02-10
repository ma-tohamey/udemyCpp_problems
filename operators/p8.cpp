#include<iostream>

using namespace std;

int main()
{

  // here he wants to teach you how to use if statment without using it
  // it is all about zero or one 
  // then multiplay it by the expresion you want it to be occure
  int n;
  cin >> n;

  bool isEven = (n % 2 == 0);

  cout << (100 * isEven) + (7 * !isEven) << endl;

}
