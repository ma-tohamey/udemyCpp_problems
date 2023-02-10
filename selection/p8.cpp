#include<iostream>

using namespace std;

int main()
{
  int a, b, c, tmp;

  cin >> a >> b >> c;

  if (c > 100)
  {
    c = -1;
  }
  if ((a < 100) && (a > c))
  {
    tmp = a;
    a = c;
    c = tmp;
  }
  if ((b < 100) && (b > c))
  {
    tmp = b;
    b = c;
    c = tmp;
  }

  cout << c << endl;
}
