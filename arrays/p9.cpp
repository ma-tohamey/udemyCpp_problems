#include<iostream>

using namespace std;

int main()
{
  int n, number, s1, s2, s3, tmp1, tmp2;

  cin >> n;
  
  for (int i = 0; i < n; i++)
  {
    cin >> number;

    if ((number < s1 && i >= 1) || (i == 0))
    {
      tmp1 = s1;
      s1 = number;
      tmp2 = s2;
      s2 = tmp1;
      s3 = tmp2;
    }
    else if ((number < s2 && i >= 2) || (i == 1))
    {
      tmp1 = s2;
      s2 = number;
      s3 = tmp1;
    }
    else if ((number < s3 && i >= 3)|| (i == 2))
    {
      s3 = number;
    }
  }

  cout << s1 << " " << s2 << " " << s3 << endl;
}
