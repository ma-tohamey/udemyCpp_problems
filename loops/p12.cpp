#include<iostream>

using namespace std;

int main()
{
  int num, multi_num, num_start = 1, multi_start;
  cin >> num >> multi_num;

  while (num > 0)
  {
    multi_start = 1;
    while (multi_num >= multi_start)
    {
      cout << num_start << " * " << multi_start << " = " << num_start * multi_start << "\n";
      multi_start++;
    }
    num_start++;
    num--;
  }
  return 0;
}
