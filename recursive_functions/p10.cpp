#include <iostream>
using namespace std;

void accumulate_arr(int arr[], int len) {
  if (len == 0) {
    return;
  }
  accumulate_arr(arr, len - 1);
  arr[len - 1] += arr[len - 2];
}
int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;
  for (int i = 0; i < number; i++)
    cin >> arr[i];

  accumulate_arr(arr, number);

  for (int i = 0; i < number; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
