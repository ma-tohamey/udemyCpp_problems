#include<iostream>

using namespace std;

int main()
{
  int count = 0, sum = 18;

  for (int x = 50; x <= 300; x++)
  {
    for (int y = 70; y <= 400; y++)
    {
      int sum = x + y;
      if (x < y && (sum % 7 == 0))
      {
        count++;
      }
    }
  }
  cout << count << endl;
}
