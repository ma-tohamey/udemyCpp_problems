#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
  int arr[]{1, 2, 3};

  for (auto val : arr)
    cout << val << " ";
  cout << endl;

  deque<int> q{1, 2, 3, 4, 5};

  for (const auto &val : q) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
