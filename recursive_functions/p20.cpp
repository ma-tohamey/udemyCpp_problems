#include <iostream>
using namespace std;

long fibonacci(long arr[], int n, int start = 2) {
  if (n <= 1)
    return 1;

  arr[start] = arr[start - 1] + arr[start - 2];

  if (start == n)
    return arr[n];

  return fibonacci(arr, n, start + 1);
}
int main(int argc, char *argv[]) {
  int number;
  long arr[100];
  cout << sizeof(arr) << endl;
  arr[0] = 1, arr[1] = 1;
  cin >> number;
  cout << fibonacci(arr, number) << endl;
  return 0;
}
// int fibonacci(int n) {
//   if (n <= 1)
//     return 1;
//
//   return fibonacci(n - 1) + fibonacci(n - 2);
// }
// int main(int argc, char *argv[]) {
//   int number;
//   cin >> number;
//   cout << fibonacci(number) << endl;
//   return 0;
// }
