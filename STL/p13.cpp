#include <iostream>
#include <vector>

using namespace std;

vector<int> asteroids_collision(vector<int> nums) {
  vector<int> res;
  for (int n : nums) {

    bool losed_asteroid = false;

    while (!res.empty() && res.back() > 0 && n < 0) {
      if (res.back() < -n)
        res.pop_back();
      else if (res.back() == -n)
        res.pop_back(), losed_asteroid = true;
      else if (res.back() > -n) {
        losed_asteroid = true;
        break;
      }
    }
    if (!losed_asteroid)
      res.push_back(n);
  }
  return res;
}

int main(int argc, char *argv[]) {
  // vector<int> v{5, 10, -5};
  // vector<int> v{1, 2, 3, 4, -5};
  // vector<int> v{8, -8};
  // vector<int> v{-2, -1, 1, 2};
  vector<int> v{10, 2, -5};
  auto res = asteroids_collision(v);
  for (int n : res)
    cout << n << ' ';
  cout << endl;
  return 0;
}
