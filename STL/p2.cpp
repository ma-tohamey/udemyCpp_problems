#include <iostream>
#include <vector>

using namespace std;

int sum_stack(vector<int> s) {
  int sum{0};
  for (int num : s)
    sum += num;
  return sum;
}
int max_3stack_sum(vector<int> &a, vector<int> &b, vector<int> &c) {
  int a_sum = sum_stack(a);
  int b_sum = sum_stack(b);
  int c_sum = sum_stack(c);

  while (a_sum != b_sum || b_sum != c_sum) {
    if (a_sum > b_sum || a_sum > c_sum) {
      a_sum -= a.back();
      a.pop_back();
      // a_sum = sum_stack(a);
    } else if (b_sum > a_sum || b_sum > c_sum) {
      b_sum -= b.back();
      b.pop_back();
      // b_sum = sum_stack(b);
    } else {
      c_sum -= c.back();
      c.pop_back();
      // c_sum = sum_stack(c);
    }
  }

  return a_sum;
}
int main(int argc, char *argv[]) {
  vector<int> a{1, 2, 3, 4};
  vector<int> b{2, 2, 2, 4, 0};
  vector<int> c{0, 3, 3, 5};

  // vector<int> a{1, 2, 3, 4};
  // vector<int> b{2, 2, 2, 4, 0};
  // vector<int> c{12, 3, 3, 5};

  cout << max_3stack_sum(a, b, c) << endl;
  return 0;
}
