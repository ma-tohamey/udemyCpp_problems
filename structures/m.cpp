#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // int i = 3;
  // int *ptr = &i;
  // int &ref = i;

  char name[8];
  // cout << *name << endl;
  name[0] = 'm';
  name[1] = 'a';
  name[2] = 'h';
  name[3] = 'm';
  name[4] = 'o';
  name[5] = 'u';
  name[6] = 'd';
  name[7] = '\0';

  for (int i = 0; i < 8; i++)
    cout << name[i];
  cout << endl;
  cout << name[0] << endl;

  // cout << i << " " << ptr << " " << &ref << endl;
  return 0;
}
