#include <iostream>
using namespace std;

double average(int arr[], int len) {
  if (len == 1)
    return arr[0];

  return ((average(arr, len - 1) + arr[len - 1]) / len);
}
int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;
  for (int i = 0; i < number; i++)
    cin >> arr[i];
  cout << average(arr, number) << endl;
  return 0;
}
