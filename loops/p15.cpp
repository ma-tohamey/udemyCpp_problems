#include<iostream>

using namespace std;

int main()
{
  int n, m, w;
  cin >> n >> m >> w;

  int cnt = 0;
  for (int a = 1; a <= n; a++)
  {
    for (int b = 1; b <= m; b++)
    {
      int c = a + b;
      if (1 <= c && c <= w)
      {
        cnt += w - c + 1;
      }
    }
  }
  cout << cnt << endl;
}
