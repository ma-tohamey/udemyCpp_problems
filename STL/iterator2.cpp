#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int arr[]{1, 2, 3};
  for (int val : arr)
    cout << val << " ";
  cout << endl;

  deque<int> q{1, 2, 3, 4, 5, 6};
  for (int val : q)
    cout << val << " ";
  cout << endl;

  deque<int>::iterator it = find(q.begin(), q.end(), 5);
  if (it != q.end())
    cout << "i found the number" << endl;
  else
    cout << "i didn't found the number" << endl;
  return 0;
}
