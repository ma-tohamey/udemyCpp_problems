#include<iostream>

using namespace std;

int main()
{
  int n1, n2, n3;

  cin >> n1 >> n2 >> n3;

  int minN = n1;

  if (n1 > n2)
    minN = n2;

  if (minN > n3)
    minN = n3;

  cout << minN << endl;

  return 0;
}
