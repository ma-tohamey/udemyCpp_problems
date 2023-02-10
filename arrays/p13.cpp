#include<iostream>

using namespace std;

int main()
{
  // better solution you can just see if it is zero then print it else don't print it 
  int const N = 501;
  int n, numbers[N] = {0}, value;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> value;
    if (numbers[value] == 0) // the whole array is zerso if it was visited so print it and change it to 1
    {
      cout << value << " ";
      numbers[value] = 1;
      // numbers[value] = unique_pos;
      // unique[unique_pos - 1] = value;
      // unique_pos++;
    }
  }

  // for (int i = 0; i < unique_pos - 1; i++)
  // {
  //   cout << unique[i] << " ";
  // }
  cout << endl;
  return 0;
}
