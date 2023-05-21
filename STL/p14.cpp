#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> next_greater_element(vector<int> nums) {
  vector<int> result(nums.size(), 0);
  stack<int> s;

  for (int i = nums.size() - 1; i >= 0; i--) {
    while (!s.empty() && nums[i] > s.top())
      s.pop();

    if (!s.empty() && nums[i] < s.top())
      result[i] = s.top();

    s.push(nums[i]);
  }
  return result;
}

int main(int argc, char *argv[]) {
  // vector<int> v{10, 5, 7, 15, 11};
  vector<int> v{73, 74, 75, 71, 69, 72, 76, 73};
  // vector<int> v{3, 15, 10, 13};
  // vector<int> v{100, 70, 30};

  for (int n : next_greater_element(v))
    cout << n << ' ';
  cout << endl;
  return 0;
}
