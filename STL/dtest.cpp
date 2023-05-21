#include <deque>
#include <iostream>
#include <vector>

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
  std::vector<int> result;
  std::deque<int> dq;

  for (int i = 0; i < nums.size(); i++) {
    // Remove elements outside of the current window from the front of the deque
    if (!dq.empty() && dq.front() == i - k) {
      dq.pop_front();
    }

    // Remove elements smaller than the current element from the back of the
    // deque
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
      dq.pop_back();
    }

    // Add the current element to the back of the deque
    dq.push_back(i);

    // Add the maximum element of the current window to the result
    if (i >= k - 1) {
      result.push_back(nums[dq.front()]);
    }
  }

  return result;
}

int main() {
  std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  std::vector<int> result = maxSlidingWindow(nums, k);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
