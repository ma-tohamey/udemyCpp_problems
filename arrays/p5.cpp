#include<iostream>

using namespace std;

int main()
{
  const int N = 200;

  int numbers[N], n, max = -1, mini = 2000;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
    if (numbers[i] > max)
    {
      max = numbers[i];
    }
    if (numbers[i] < mini)
    {
      mini = numbers[i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (numbers[i] == max)
    {
      numbers[i] = mini;
    }
    else if (numbers[i] == mini)
    {
      numbers[i] = max;
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
}
