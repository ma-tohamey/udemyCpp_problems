#include<iostream>

using namespace std;

int main()
{
  int num, start = 0;
  cin >> num;

  while (num > start)
  {
    if ((start % 8 == 0) || ((start % 4 == 0) && (start % 3 == 0)))
    {
      cout << start << " ";
    }
    start++;
  }
  cout << endl;
}
