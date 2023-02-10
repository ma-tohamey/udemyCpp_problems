#include<iostream>

using namespace std;

int main()
{
  // without using even arrays at all
  
  int n, old_n, new_n;

  cin >> n;

  old_n = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> new_n;

    if (old_n != new_n)
    {
      cout << new_n << " ";
      old_n = new_n;
    }
  }
  cout << endl;
  return 0;
}






  // using only 1 single array

  
  // int num, unique_list[1000];
  //
  // cin >> num;
  //
  // for (int i = 0; i < num; i++)
  // {
  //   cin >> unique_list[i];
  // }
  // cout << unique_list[0] << " ";
  //
  // for (int i = 1; i < num; i++)
  // {
  //   if (unique_list[i] != unique_list[i-1])
  //   {
  //     cout << unique_list[i] << " ";
  //   }
  // }
  // cout << endl;
// }
