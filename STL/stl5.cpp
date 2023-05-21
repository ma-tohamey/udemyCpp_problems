#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> sliding_window_maximum(vector<int> nums, int k) {
  vector<int> max_nums;
  multiset<int> k_nums;

  for (int i = 0; i < k; i++)
    k_nums.insert(-nums[i]);

  max_nums.push_back(-*k_nums.begin());

  int nums_size = nums.size();
  for (int i = k; i < nums_size; i++) {
    k_nums.insert(-nums[i]);
    k_nums.erase(k_nums.find(-nums[i - k]));
    max_nums.push_back(-*k_nums.begin());
  }

  return max_nums;
}

int main(int argc, char *argv[]) {
  vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
  int k;
  cin >> k;
  for (int num : sliding_window_maximum(v, k))
    cout << num << ' ';
  cout << endl;
  return 0;
}
