#include<iostream>

using namespace std;

int main()
{
  int n, tmp;

  cin >> n;
  int numbers[n];

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  for (int i = 0, j = n - 1; i < (n / 2); i++, j--)
  {
    tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
  }

  for (int i = 0; i < n; i++)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
  return 0;
}
