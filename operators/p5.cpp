#include<iostream>

using namespace std;

int main()
{
  int num;

  cin >> num;

  // Is even using %2
  bool isEven1 = (num % 2 == 0);

  // is even using / 2;
  bool isEven2 = ((num / 2.0) - (num / 2) == 0.0);

  // is even using %10;
  bool isEven3 = (num % 10 == 0)||(num % 10 == 2)||(num % 10 == 4)||(num % 10 == 6)||(num % 10 == 8);

  cout << isEven1 << endl;
  cout << isEven2 << endl;
  cout << isEven3  << endl;

  return 0;
}
