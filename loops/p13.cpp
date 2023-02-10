#include<iostream>

using namespace std;

int main()
{
  int test_cases, cases_num, cases_start, number, power, power_sum, sum;
  cin >> test_cases;

  while (test_cases)
  {
    cin >> cases_num;
    cases_start = 1;
    sum = 0;
    while (cases_start <= cases_num)
    {
      power = cases_start;
      power_sum = 1;
      cin >> number;
      while (power > 0)
      {
        power_sum = power_sum * number; 
        power--;
      }
      sum += power_sum;
      cases_start++;
    }

    cout << sum << endl;
    test_cases--;
  }
}
