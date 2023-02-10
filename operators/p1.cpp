#include<iostream>

using namespace std;

int main()
{
  int nb, ng, nt;

  cin >> nb >> ng >> nt;

  cout << (nb > 25) << endl;
  cout << (ng <= 30) << endl;
  cout << (nb > 20 && nt > 2 || ng > 30 && nt > 4) << endl;
  cout << (nb < 60 || ng < 70) << endl;
  cout << (!(nb >= 60) && !(ng >= 70)) << endl;
  cout << ((nb - ng) == 10) << endl;
  cout << ((nb - ng) > 10 || nt > 5) << endl;
  cout << ((nb - ng == 10) || (ng - nb == 15)) << endl;
}
