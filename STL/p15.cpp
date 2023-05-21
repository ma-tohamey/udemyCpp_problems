#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> next_greater_element(vector<int> nums) {
  vector<int> result(nums.size(), -1);
  stack<int> s;

  for (int i = nums.size() - 1; i >= 0; i--)
    s.push(nums[i]);

  for (int i = nums.size() - 1; i >= 0; i--) {
    while (!s.empty() && nums[i] >= s.top())
      s.pop();

    if (!s.empty() && nums[i] < s.top())
      result[i] = s.top();

    s.push(nums[i]);
  }

  return result;
}

int main(int argc, char *argv[]) {
  vector<int> v{1, 2, 3, 4, 3};
  // vector<int> v{5, 4, 3, 2, 1};
  // vector<int> v{1, 2, 1};
  for (int n : next_greater_element(v))
    cout << n << ' ';
  cout << endl;
  return 0;
}
