#include <iostream>
using namespace std;

void left_max(int arr[], int len) {
  if (len == 1)
    return;

  left_max(arr + 1, len - 1);

  if (arr[0] < arr[1])
    arr[0] = arr[1];
}

int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;
  for (int i = 0; i < number; i++)
    cin >> arr[i];

  left_max(arr, number);

  for (int i = 0; i < number; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
