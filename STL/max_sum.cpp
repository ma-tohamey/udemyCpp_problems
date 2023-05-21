#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int stack_sum(vector<int> &s) {
  int sum = 0;
  for (auto &value : s)
    sum += value;
  return sum;
}

int max_3stack_sum(vector<int> &a, vector<int> &b, vector<int> &c) {

  while (!(a.empty() && !(b.empty()) && !(c.empty()))) {
    int a_sum = stack_sum(a), b_sum = stack_sum(b), c_sum = stack_sum(c);

    if (a_sum == b_sum && b_sum == c_sum)
      return a_sum;

    if (a_sum >= b_sum && a_sum >= c_sum)
      a_sum -= a.back(), a.pop_back();

    else if (b_sum >= a_sum && b_sum >= c_sum)
      b_sum -= b.back(), b.pop_back();

    else
      c_sum -= c.back(), c.pop_back();
  }
  return 0;
}

int main(int argc, char *argv[]) {
  vector<int> a{1, 2, 3, 4}, b{2, 2, 2, 4, 0}, c{0, 3, 3, 5};
  // vector<int> a{1, 2, 3}, b{1, 2, 3}, c{1, 2, 3};
  cout << max_3stack_sum(a, b, c) << endl;
  return 0;
}
