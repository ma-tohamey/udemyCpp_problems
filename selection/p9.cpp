#include<iostream>

using namespace std;

int main()
{
  int x, n1, n2, n3, n4, n5;
  cin >> x >> n1 >> n2 >> n3 >> n4 >> n5;

  int more_than = 0;

  more_than += (n1 > x);
  more_than += (n2 > x);
  more_than += (n3 > x);
  more_than += (n4 > x);
  more_than += (n5 > x);

  int less_or_equal = 5 - more_than;

  // my solution
  // int more_than = 0;
  //
  // if (n1 > x)
  // {
  //   more_than++;
  // }
  // if (n2 > x)
  // {
  //   more_than++;
  // }
  // if (n3 > x)
  // {
  //   more_than++;
  // }
  // if (n4 > x)
  // {
  //   more_than++;
  // }
  // if (n5 > x)
  // {
  //   more_than++;
  // }
  //
  // int less_or_equal = 5 - more_than;

  cout << less_or_equal << " " << more_than << endl;
}
