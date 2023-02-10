#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  bool isEven = (n % 2 == 0);

  if (isEven)
    cout << n % 10 << "\n";

  else
    if (n < 1000)
      cout << n % 100 << "\n";
    else if (n > 1000 && n < 1000000)
      cout << n % 10000 << "\n"; 
    else 
      cout << -n << "\n";

  return 0;
}
