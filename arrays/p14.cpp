#include <iostream>

using namespace std;

int main() {
  int const N = 501;
  int n, numbers[N] = {0}, value, min = 500, max = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> value;

    /* specifiying the starting and ending point */
    if (value > max) {
      max = value;
    }
    if (value < min) {
      min = value;
    }

    numbers[value]++;
  }

  /* And you can do better by knowing
  the minimum and maximum number so you don't
  have to iterate on the entire array */

  for (int i = min; i < max; i++) {
    while (numbers[i]) {
      cout << i << " ";
      numbers[i]--;
    }
  }
  cout << endl;
}
