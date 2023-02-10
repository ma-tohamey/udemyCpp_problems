#include<iostream>

using namespace std;

int main()
{
  int n;
  char ch;

  cin >> n >> ch;

  while (n > 0)
  {
    cout << ch;
    n--;
  }
  cout << endl;
  return 0;
}
