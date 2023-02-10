#include<iostream>

using namespace std;

int main()
{
  int n1, n2;

  cout << "Input: ";
  cin >> n1 >> n2;

  int result = n1 - (n1 / n2) * n2;

  cout << "nice one: " << result << endl;


  return 0;
}
