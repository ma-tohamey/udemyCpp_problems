#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  bool is_even = false;
  double oddsSum = 0, evensSum = 0, num;
  int oddsNum = 0, evensNum = 0;

  while (n > 0)
  {
    cin >> num;
     if (is_even)
     {
       evensSum += num;
       evensNum++;
       is_even = false;
     }
     else
     {
       oddsSum += num;
       oddsNum++;
       is_even = true;
     }
     n--;
  }

  cout << (oddsSum / oddsNum) << " " << (evensSum / evensNum) << endl; 
}
