#include <iostream>

using namespace std;

int main() {
  int n, k, sum = 0, numbers[200], max = 0, idx;

  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  for (int i = 0; i < n; i++) {
    if (i < k) {
      sum += numbers[i];
      idx = i;
      continue;
    }

    max = sum;
    sum = sum + numbers[i] - numbers[i - k];

    if (sum > max) {
      max = sum;
      idx = i;
    }
  }

  cout << idx - (k - 1) << " " << idx << " " << max << endl;

  return 0;
}
