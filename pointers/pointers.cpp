#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  // not constant value
  int val1 = 20;

  // constant value
  const int val2 = 30;

  // constant value
  const int val3 = 40;

  // constant pointer value
  int *const ptr1 = &val1;

  // the value of what pointer point at is constant
  const int *ptr2 = &val2;

  // constant pointer points to costant value
  const int *const ptr3 = &val3;

  // *ptr1 = 20;
  // val1 = 20;
  // ptr1 = &val3;

  // int arr[]{3, 5, 7, 9};
  //
  // int *p = arr;
  // p[-1]--;
  // p[+1]++;
  //
  // for (auto &val : arr)
  //   cout << val << " ";
  // string str = "mahmoud";
  // str[-1]--;
  // // char str[]{"mahmoud"};
  // char *ch = &str[0];
  // // while (*ch != '\0')
  // cout << *ch++;
  // cout << endl;
  return 0;
}
