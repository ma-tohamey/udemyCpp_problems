#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(int arr[], int len) {
  if (len <= 0)
    return true;

  if (arr[0] != arr[len - 1])
    return false;

  return is_palindrome(arr + 1, len - 2);
}
int main(int argc, char *argv[]) {
  int arr[100], number;
  cin >> number;

  for (int i = 0; i < number; i++)
    cin >> arr[i];

  if (is_palindrome(arr, number))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
