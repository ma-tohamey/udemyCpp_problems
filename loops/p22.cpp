#include<iostream>

using namespace std;

int main()
{
  int n, a, b, sum = 0;
  cin >> n >> a >> b;

  for (int num = 1; num <= n; num++)
  {
    int digits_sum = 0, tmp_num = num;
    while (tmp_num)
    {
      digits_sum += tmp_num % 10;
      tmp_num /= 10;
    }
    if (a <= digits_sum && digits_sum <= b)
    {
      sum += num;
    }
  }
  cout << sum << endl;
}
