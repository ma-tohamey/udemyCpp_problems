#include <iostream>

using namespace std;

int main()
{
  float a, b, c, d, e;

  cin >> a >> b >> c >> d >> e;

  cout << "A) : " << (a + b + c + d + e) / 5 << endl;

  cout << "B) : " << (a + b + c) / (d + e) << endl;

  cout << "C) : " << ( ((a + b + c) / 3) / ( (d + e) / 2) ) << endl;

}
