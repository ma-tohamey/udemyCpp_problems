#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  if (n < 10000)
  {
    cout << "this is a samll number" << "\n";
  }
  else
  {
    int stDigit = n / 100;
    int ndDigit = (n % 100) / 10;
    int rdDigit = n % 10;

    int sumLast3Digit = stDigit + ndDigit + rdDigit;

    bool isOdd = !(sumLast3Digit % 2 == 0);
    
    if (isOdd)
      cout << "this is a great number" << "\n";
    else
    {
      if ((stDigit % 2 != 0) || (ndDigit % 2 != 0) || (rdDigit % 2 != 0))
      {
        cout << "this is a good number" << "\n";
      }
      else
      {
        cout << "this is a bad number" << "\n";
      }
    }


  }
}
