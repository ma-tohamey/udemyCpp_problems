#include<iostream>

using namespace std;

int main()
{
  int user_num, tmp;
  cin >> user_num;

  int n_cols = (user_num * 2) - 1, n_rows = user_num;
  int spaces = n_cols / 2, stars = 1;

  bool is_mirror = false;

  user_num *= 2;
  while (user_num > 0)
  {
    if (user_num == n_rows)
    {
      is_mirror = true;
      stars = n_cols;
      spaces = 0;
    }

    tmp = spaces;
    while (spaces > 0) // for making spaces
    {
      cout << " ";
      spaces--;
    }
    if (!is_mirror)
    {
      spaces = tmp - 1;
    }
    else
    {
      spaces = tmp + 1;
    }

    
    tmp = stars;
    while (stars > 0) // for making stars
    {
      cout << "*";
      stars--;
    }
    if (!is_mirror)
    {
      stars = tmp + 2;
    }
    else
    {
      stars = tmp - 2;
    }

    user_num--;
    cout << "\n";
  }
}
