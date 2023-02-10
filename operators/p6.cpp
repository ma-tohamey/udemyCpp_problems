#include<iostream>

using namespace std;

int main()
{
  // solutin using modulas 

  int n;
  cin >> n;
  
  int stDigit = n % 10;
  n = n / 10;

  int ndDigit = n % 10;
  n = n / 10;

  int rdDigit = n % 10;
  n = n / 10;

  cout << stDigit + ndDigit + rdDigit << endl;

  return 0;

  // solution using devision
  //
  // int n, stDigit, ndDigit, rdDigit, tmp;
  // cin >> n;
  //
  // tmp = n / 1000;
  // n = n - (tmp * 1000);
  //
  // stDigit = n / 100;
  //
  // tmp = n - (stDigit * 100);
  // ndDigit = tmp / 10;
  //
  // rdDigit = tmp - (ndDigit * 10);
  //
  // cout << stDigit + ndDigit + rdDigit << endl;
  //
  // return 0;
}
