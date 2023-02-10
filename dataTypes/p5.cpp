#include<iostream>

using namespace std;

int main()
{
  int num1, num2, num3, tmp = -1;

  cin >> num1 >> num2 >> num3;

  cout << num1 << " " << num2 << " " << num3 << "\n";

  tmp = num1;
  num1 = num2;
  num2 = num3;
  num3 = tmp;
  
  cout << num1 << " " << num2 << " " << num3 << "\n";

  return 0;
}
