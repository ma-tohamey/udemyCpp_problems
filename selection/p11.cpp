#include<iostream>

using namespace std;

int main()
{
  int n, a, biggest;
  
  cin >> n;
  if (n < 2 || n > 10)
  {
    return 0;
  }

  cin >> a;
  cin >> biggest;
  if (a > biggest)
  {
    biggest = a;
  }
  if (n >= 3)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 4)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 5)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 6)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 7)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 8)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 9)
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }
  if (n >= 10) 
  {
    cin >> a;
    if (a > biggest)
    {
      biggest = a;
    }
  }

  cout << biggest << endl;

}
