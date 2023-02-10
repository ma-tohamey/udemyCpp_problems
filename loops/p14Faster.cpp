#include<iostream>

using namespace std;

int main()
{
  int n, m, sum;
  cin >> n >> m >> sum;

  int cnt = 0;

  for (int a = 1; a <= n; a++)
  {
    int b = sum - a;
    if (b >= 1 && b <= m)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}
