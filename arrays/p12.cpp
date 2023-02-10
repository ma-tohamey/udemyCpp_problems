#include<iostream>

using namespace std;

int main()
{
  int n, frequency[10] = {0}, value;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> value;

    if (value == 0)
    {
      frequency[0]++;
    }

    while (value)
    {
      frequency[value % 10]++;
      value /= 10;
    }
  }

  for (int i = 0; i < 10; i++)
  {
    cout << i << " " << frequency[i] << endl;
  }
  return 0;
}
