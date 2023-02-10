#include<iostream>

using namespace std;

int main()
{
  int x, s1, e1, s2, e2, s3, e3;
  cin >> x >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;

  int result = 0;

  // much nicer and cleaner
  result += (s1 <= x && x <= e1);
  result += (s2 <= x && x <= e2);
  result += (s3 <= x && x <= e3);

  // my solution
  // if (s1 <= x && x <= e1)
  // {
  //   result++;
  // }
  // if (s2 <= x && x <= e2)
  // {
  //   result++;
  // }
  // if (s3 <= x && x <= e3)
  // {
  //   result++;
  // }

  cout << result << endl;
}
