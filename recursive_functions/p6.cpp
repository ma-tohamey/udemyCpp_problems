#include <iostream>
using namespace std;

int arr_max(int arr[], int len) {
  if (len == 1)
    return arr[0];

  if (arr[len - 1] > arr_max(arr, len - 1))
    return arr[len - 1];
  return arr_max(arr, len - 1);
}
int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;
  for (int i = 0; i < number; i++)
    cin >> arr[i];

  cout << arr_max(arr, number) << endl;
  return 0;
}
