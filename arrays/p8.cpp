#include<iostream>

using namespace std;

int main()
{
  const int N = 200;
  int n, numbers[N];

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  int mini, sum;
  bool first_time = true;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      sum = numbers[i] + numbers[j] + j - i;
      if (first_time || sum < mini)
      {
        min = sum;
        first_time = false;
      }
    }
  }
  cout << mini << endl;
  return 0;
}
