#include <iostream>

using namespace std;

int main() {
  int const N = 200;
  bool numbers[N] = {0};
  int n, k, tmp_n, steps, c_cell = 1;
  cin >> n >> k;

  tmp_n = n;
  while (n) {
    steps = k % n;
    if (steps == 0) {
      steps = n;
    }

    // int last_person = -1;
    // // udemy solution
    // while (steps) {
    //   if (numbers[c_cell] == 0)
    //     last_person = c_cell, steps--;
    //   c_cell = (c_cell + 1) % tmp_n;
    // }
    //
    // this was my solution
    while (steps) {
      if (numbers[c_cell] == 0 && c_cell < tmp_n + 1) {
        steps--;
        if (steps == 0) {
          break;
        }
        c_cell++;
      } else {
        if (c_cell == tmp_n + 1) {
          c_cell = 1;
        } else {
          c_cell++;
        }
      }
    }

    numbers[c_cell] = 1;
    cout << c_cell << " ";

    // my solution how to handle c_cell
    if (c_cell == tmp_n) {
      c_cell = 1;
    }
    n--;
  }
  cout << endl;
  return 0;
}
