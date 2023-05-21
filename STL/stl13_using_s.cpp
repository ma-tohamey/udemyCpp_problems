#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
  vector<int> result;
  for (int &asteroid : asteroids) {
    bool is_equal = false;
    while ((!result.empty()) && (asteroid < 0 && result.back() > 0)) {
      int asteroid_size = -asteroid;
      if (asteroid_size > result.back()) {
        result.pop_back();
        continue;
      } else if (asteroid_size == result.back())
        result.pop_back();
      is_equal = true;
    }
    if (!is_equal)
      result.push_back(asteroid);
  }
  return result;
}

int main(int argc, char *argv[]) {

  int cases, asteroid;
  vector<int> v;
  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cin >> asteroid;
    v.push_back(asteroid);
  }

  auto asteroids_result = asteroidCollision(v);

  for (int ast : asteroids_result)
    cout << ast << ' ';
  cout << endl;
  return 0;
}
