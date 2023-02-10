#include <iostream>

using namespace std;

int main() {
  int n, numbers[200], answer = 0, counter = 1;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  for (int i = 1; i < n; i++) {
    if (numbers[i - 1] <= numbers[i]) {
      answer += counter;
      counter++;
    } else {
      counter = 1;
    }
  }

  cout << answer + n << endl;
  return 0;
}
