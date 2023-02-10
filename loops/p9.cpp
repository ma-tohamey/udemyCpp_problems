#include<iostream>

using namespace std;

int main()
{
  int test_cases, cases_num, min_num, current_num;

  cin >> test_cases;
  while (test_cases > 0)
  {
    cin >> cases_num;
    cin >> current_num;
    min_num = current_num;

    while ((cases_num - 1) > 0)
    {
      cin >> current_num;
      if (current_num < min_num)
      {
        min_num = current_num;
      }
      --cases_num;
    }
    --test_cases;
    cout << min_num << endl;
  }
}
