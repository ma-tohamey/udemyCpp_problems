#include<iostream>

using namespace std;

int main()
{
  int days, totalYears, totalMonths;
  cin >> days;

  totalYears = days / 360;

  days = days % 360;

  totalMonths = days / 30;
  days = days % 30;

  cout << totalYears << " " << totalMonths << " " << days << endl;

  return 0;
}
