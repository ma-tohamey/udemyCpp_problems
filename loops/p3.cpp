#include<iostream>

using namespace std;

int main()
{
  int n, cnt, tmp;
  cin >> n;

  n = (n * (n + 1))/2;
  tmp = n;
  cnt = 1;

  while (n > 0)
  {
    if ( (tmp - cnt) == n )
    {
      cout << "\n";
      tmp -= cnt;
      cnt++;
    }
    cout << '*';
    n--;
  }
  cout << endl;
  return 0;
}
