#include<iostream>

using namespace std;

int main()
{
  int n, m, sum;
  cin >> n >> m >> sum;

  int cnt = 0;
  for (int a = 1; a <= n; a++)
  {
    for (int b = 1; b <= m; b++)
    {
      if (a + b == sum)
      {
        cnt++;
        break;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
