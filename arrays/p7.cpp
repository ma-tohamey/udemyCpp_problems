#include<iostream>

using namespace std;

int main()
{
  const int N = 1000;
  int n, numbers[N];
  string answer = "YES";

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  for (int i = 0, j = n; i < n / 2; i++, j--)
  {
    if (numbers[i] != numbers[j-1])
    {
      answer = "NO";
      break;
    }
  }
  cout << answer << endl;
  return 0;
}
