#include <iostream>
using namespace std;

void array_increment(int arr[], int len) {
  if (len == 0) {
    return;
  }
  arr[len - 1] += (len - 1);
  array_increment(arr, len - 1);
}

int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;
  for (int i = 0; i < number; i++)
    cin >> arr[i];

  array_increment(arr, number);

  for (int i = 0; i < number; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
