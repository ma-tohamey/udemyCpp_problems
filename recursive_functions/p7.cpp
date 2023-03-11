#include <iostream>
using namespace std;

int sum(int arr[], int len) {
  if (len == 1)
    return arr[0];
  return sum(arr, len - 1) + arr[len - 1];
}
int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;
  for (int i = 0; i < number; i++)
    cin >> arr[i];

  cout << sum(arr, number) << endl;
  return 0;
}
