#include <iostream>
#include <vector>

using namespace std;

int stack_sum(vector<int> &s) {
  int sum = 0;
  for (auto val : s)
    sum += val;
  return sum;
}

int max_3stack_sum(vector<int> &a, vector<int> &b, vector<int> &c) {
  int a_sum = stack_sum(a), b_sum = stack_sum(b), c_sum = stack_sum(c);

  while (a_sum != b_sum || b_sum != c_sum || a_sum != c_sum) {
    if (c_sum > b_sum || c_sum > a_sum) {
      c_sum -= c.back();
      c.pop_back();
    } else if (b_sum > c_sum || b_sum > a_sum) {
      b_sum -= b.back();
      b.pop_back();
    } else if (a_sum > b_sum || a_sum > c_sum) {
      a_sum -= a.back();
      a.pop_back();
    }
  }

  return a_sum;
}
int main(int argc, char *argv[]) {
  // vector<int> a{1, 2, 3, 4};
  // vector<int> b{2, 2, 2, 4, 0};
  // vector<int> c{0, 3, 3, 5};
  // vector<int> c{12, 3, 3, 5};
  vector<int> a{};
  vector<int> b{};
  vector<int> c{};

  cout << max_3stack_sum(a, b, c) << endl;
  return 0;
}
