#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

vector<int> nextGreaterEelemnt(vector<int> &nums) {
  // first is the int, second is the index of it
  stack<pair<int, int>> s;
  vector<int> result(nums.size(), -1);
  for (int i = 0; i < nums.size(); i++) {
    while ((!s.empty()) && s.top().first < nums[i]) {
      result[s.top().second] = nums[i];
      s.pop();
    }
    s.push(make_pair(nums[i], i));
  }
  return result;
}
int main(int argc, char *argv[]) {

  int cases, num;
  vector<int> v;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cin >> num;
    v.push_back(num);
  }

  auto next_grater_result = nextGreaterEelemnt(v);

  for (int n : next_grater_result)
    cout << n << ' ';
  cout << endl;
  return 0;
}
