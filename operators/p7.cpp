#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  n = (n / 1000) % 10;

  cout << n << endl;
}
