#include<iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;

  bool aStatus = (a % 2 == 0);
  bool bStatus = (b % 2 == 0);

  if (!aStatus and !bStatus)
  {
    cout << a * b << endl;
  }
  else if (aStatus and bStatus)
  {
    cout << a / b << endl;
  }
  else if (!aStatus and bStatus)
  {
    cout << a + b << endl;
  }
  else if (aStatus and !bStatus)
  {
    cout << a - b << endl;
  }
}
