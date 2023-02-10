#include<iostream>

using namespace std;

int main()
{
  int n, start = 3;
  cin >> n;

  while (n)
  {
    if (start % 4 != 0) // when we jumping by 3 we don't need to check the first condition
                        // which is the number must be divisible by 3
    {
      cout << start << " ";
      n--;
    }
    start += 3; // adding 3 is better than adding one every time start++
  }
  cout << endl;
}
