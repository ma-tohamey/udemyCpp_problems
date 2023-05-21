#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

vector<int> max_sliding_window(vector<int> &nums, int k) {
  vector<int> max_nums;
  multiset<int> mset;

  // for (int i = 0; i < k; i++) {
  //   mset.insert(nums[i]);
  // }
  //
  // max_nums.push_back(*mset.end());
  //
  // for (int i = k; i < nums.size(); i++) {
  //   mset.erase(mset.find(nums[i - k]));
  //   mset.insert(nums[i]);
  //   max_nums.push_back(
  //       *prev(mset.end())); // using prev function to get the right end value
  //                           // i could make it in negative then get begin()
  // }

  for (int i = 0; i < k; i++) {
    mset.insert(-nums[i]);
  }

  max_nums.push_back(-*mset.begin());

  for (int i = k; i < nums.size(); i++) {
    mset.erase(mset.find(-nums[i - k]));
    mset.insert(-nums[i]);
    max_nums.push_back(
        -*mset.begin()); // using prev function to get the right end value
                         // i could make it in negative then get begin()
  }

  return max_nums;
}

int main(int argc, char *argv[]) {
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  int k;
  cin >> k;

  auto max_nums = max_sliding_window(nums, k);
  for (auto num : max_nums)
    cout << num << " ";
  cout << endl;

  return 0;
}
