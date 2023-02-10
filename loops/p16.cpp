#include<iostream>

using namespace std;

int main()
{
  // udemy solution
  //
  int n = 10, start = 0, end = 1;

  cout << start << " " << end << " ";

  for (n -= 2; n > 0; n--)
  {
    int current_num = start + end;
    start = end;
    end = current_num;
    cout << current_num << " ";
  }
  cout << endl;
  
  //
  // int num, start = 0, end = 1;
  // cin >> num;
  //
  // bool is_change = false;
  // cout << start << " " << end << " ";
  // for (num -= 2; num > 0; num--)
  // {
  //   is_change = !is_change;
  //   if (is_change)
  //   {
  //     start = start + end;
  //     cout << start << " ";
  //   }
  //   else
  //   {
  //     end = start + end;
  //     cout << end << " ";
  //   }
  // }
  // cout << endl;
}
