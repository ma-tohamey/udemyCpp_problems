#include<iostream>

using namespace std;

int main()
{
  int size;

  cin >> size;
  int numbers[200];
  string answer = "YES";

  cin >> numbers[0];
  for (int i = 1; i < size; i++)
  {
    cin >> numbers[i];

    if (numbers[i] < numbers[i-1])
    {
      answer = "NO";
    }
  }
  cout << answer << endl;
  return 0;
}
