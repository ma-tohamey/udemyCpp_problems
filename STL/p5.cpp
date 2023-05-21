#include <iostream>
// #include <set>
#include <deque>
#include <vector>

using namespace std;

vector<int> max_sliding_window(vector<int> nums, int k) {
  vector<int> res;
  deque<int> dq;
  for (int i = 0; i < nums.size(); i++) {
    // to pop if the first element in the queue is out of cnt window
    if (!dq.empty() && i - k == dq.front())
      dq.pop_front();

    // while cnt num bigger that last back element in dq >> remove it
    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    // on every time push the cnt num
    dq.push_back(i);

    // only push in res when i >= k - 1
    if (i >= k - 1)
      res.push_back(nums[dq.front()]);
  }

  return res;
}

int main(int argc, char *argv[]) {
  // vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> v{1, 1, 1, 1, 1, 4, 6};
  auto res = max_sliding_window(v, 3);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
