#include<iostream>

using namespace std;

int main()
{
  int num, current_number, new_int = 0;
  cin >> num;

  while (num > 0)
  {
    current_number = num % 10;
    num /= 10;

    // (new_int *= 10) + new_int;
    new_int = (new_int * 10) + current_number;
  }
  cout << new_int << " " <<  new_int * 3 << endl;
}
