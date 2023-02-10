#include<iostream>

using namespace std;

int main()
{
  int a, b, c, tmp;

  cin >> a >> b >> c;

  tmp = a;

  if (a > b)
  {
    tmp = a;
    a = b;
    b = tmp;
  }
  if (a > c)
  {
    tmp = a;
    a = c;
    c = tmp;
  }
  if (b > c)
  {
    tmp = b;
    b = c;
    c = tmp;
  }
  cout << a << " " << b << " " << c << endl;
}
