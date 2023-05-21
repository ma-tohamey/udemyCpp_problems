#include <iostream>
#include <vector>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
  auto cnt_num_it = asteroids.begin() + 1;
  auto prev_num_it = cnt_num_it - 1;

  while (cnt_num_it != asteroids.end()) {
    // cnt_num is negative and prev_num is positive
    bool is_collision = (*cnt_num_it < 0 && *prev_num_it > 0);
    if (is_collision) {
      // if (asteroids.size() < 2)
      //   break;
      int cnt_num_size = *cnt_num_it * -1;
      if (cnt_num_size > *prev_num_it) {
        // if negative number is bigger then erease the prev_num which is the
        // positive one and subtract it by 1 to check if the prev_num is also
        // smaller than the current one because erease function by defeault get
        // to the next item
        prev_num_it = asteroids.erase(prev_num_it) - 1;
        // subtract one from cnt_num to hold on the current negative number;
        cnt_num_it -= 1;
        // state when prev gets behind the begin;
        // if prev_num_it get out of boundries then goes to the next one
        if (prev_num_it == asteroids.begin() - 1) {
          cnt_num_it++;
          prev_num_it++;
        }

        // if the prev_num which is positive is bigger and win then
      } else if (*prev_num_it > cnt_num_size) {
        // just erease cnt_num
        // ///////////////////////////////////////////////
        // we didn't subtract from prev_num because cnt_num_it is after the
        // prev_num_it so it did nothing to prev_num_it
        // ///////////////////////////////////////////////
        cnt_num_it = asteroids.erase(cnt_num_it);
        // state when cnt_comes to end;
        if (cnt_num_it == asteroids.end())
          break;

        // if both are equal then erease both of them
      } else {
        cnt_num_it = asteroids.erase(cnt_num_it) - 1;
        prev_num_it = asteroids.erase(prev_num_it) - 1;
        if (cnt_num_it == asteroids.end())
          break;
      }
    } else {
      cnt_num_it++;
      prev_num_it++;
    }
  }
  return asteroids;
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
