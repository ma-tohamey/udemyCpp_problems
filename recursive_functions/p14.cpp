#include <iostream>
using namespace std;

int suffix_sum(int arr[], int arr_len, int sum_len) {
  if (sum_len == 0)
    return 0;

  return arr[arr_len - 1] + suffix_sum(arr, arr_len - 1, sum_len - 1);
}
int main(int argc, char *argv[]) {
  int arr[100], arr_len, sum_len;
  cin >> arr_len;
  for (int i = 0; i < arr_len; i++)
    cin >> arr[i];

  cin >> sum_len;

  cout << suffix_sum(arr, arr_len, sum_len) << endl;
  return 0;
}
