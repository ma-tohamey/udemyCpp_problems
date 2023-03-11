#include <iostream>
using namespace std;

int prefix_sum(int arr[], int arr_len, int sum_len) {
  if (sum_len == 0)
    return 0;
  // return arr[0] + prefix_sum(arr + 1, arr_len, sum_len - 1);
  return arr[sum_len - 1] + prefix_sum(arr, arr_len, sum_len - 1);
}

int main(int argc, char *argv[]) {
  int arr[100], arr_len, sum_len;
  cin >> arr_len;
  for (int i = 0; i < arr_len; i++)
    cin >> arr[i];
  cin >> sum_len;

  cout << prefix_sum(arr, arr_len, sum_len) << endl;
  return 0;
}
