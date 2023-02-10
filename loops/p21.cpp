#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  if (n <= 0)
  {
    cout << "please enter a valid number";
  }
  else if (n == 1)
  {
    cout << 2 << endl;
  }
  else
  {
    cout << 2;
    for (int start = 3; start <= n; start++)
    {
      bool is_prime = true;
      for (int num = 2; num < start; num++)
      {
        if (start % num == 0)
        {
          is_prime = false;
          break;
        }
      }
      if (is_prime)
      {
        cout << "," << start;
      }
    }
  }
  cout << endl;
}
