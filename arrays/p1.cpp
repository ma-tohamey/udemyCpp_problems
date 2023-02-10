#include<iostream>

using namespace std;

int main()
{
  int cases, tmp;
  cin >> cases;

  int number[cases];

  for(int i = 0; i < cases; i++)
  {
    cin >> number[i];

    if (number[i] > number[0])
    {
      tmp = number[0];
      number[0] = number[i];
      number[i] = tmp;
    }
    if (number[i] > number[1])
    {
      tmp = number[1];
      number[1] = number[i];
      number[i] = tmp;
    }
  }
  cout << number[0] << " " << number[1] << endl;
  cout << number[0] + number[1];
}
