#include <iostream>
using namespace std;

void left_max(int arr[], int len, int start_position = 0) {
  if (start_position == len - 1)
    return;

  left_max(arr, len, start_position++);

  if (arr[start_position] < arr[start_position + 1])
    arr[start_position] = arr[start_position + 1];
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
