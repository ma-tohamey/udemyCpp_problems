#include <iostream>

using namespace std;

void set_powers(int arr[], int len = 5, int m = 2) {
  arr[0] = 1;
  for (int i = 1; i < len; i++) {
    arr[i] = arr[i - 1] * m;
  }
};

int main(int argc, char *argv[]) {
  int array[100], len, m;
  cout << "len = ";
  cin >> len;
  cout << "m = ";
  cin >> m;

  set_powers(array, len, m);

  for (int i = 0; i < len; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}
