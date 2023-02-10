#include<iostream>

using namespace std;

int main()
{
  int num, cnt, tmp;
  cin >> num;

  cnt = num;
  num = (num * (num + 1)) / 2;
  tmp = num;

  while (num > 0)
  {
    if (num == (tmp - cnt))
    {
      cout << "\n";
      tmp -= cnt;
      cnt--;
    }
    cout << '*';
    num--;
  }
  cout << endl;

  return 0;
}
