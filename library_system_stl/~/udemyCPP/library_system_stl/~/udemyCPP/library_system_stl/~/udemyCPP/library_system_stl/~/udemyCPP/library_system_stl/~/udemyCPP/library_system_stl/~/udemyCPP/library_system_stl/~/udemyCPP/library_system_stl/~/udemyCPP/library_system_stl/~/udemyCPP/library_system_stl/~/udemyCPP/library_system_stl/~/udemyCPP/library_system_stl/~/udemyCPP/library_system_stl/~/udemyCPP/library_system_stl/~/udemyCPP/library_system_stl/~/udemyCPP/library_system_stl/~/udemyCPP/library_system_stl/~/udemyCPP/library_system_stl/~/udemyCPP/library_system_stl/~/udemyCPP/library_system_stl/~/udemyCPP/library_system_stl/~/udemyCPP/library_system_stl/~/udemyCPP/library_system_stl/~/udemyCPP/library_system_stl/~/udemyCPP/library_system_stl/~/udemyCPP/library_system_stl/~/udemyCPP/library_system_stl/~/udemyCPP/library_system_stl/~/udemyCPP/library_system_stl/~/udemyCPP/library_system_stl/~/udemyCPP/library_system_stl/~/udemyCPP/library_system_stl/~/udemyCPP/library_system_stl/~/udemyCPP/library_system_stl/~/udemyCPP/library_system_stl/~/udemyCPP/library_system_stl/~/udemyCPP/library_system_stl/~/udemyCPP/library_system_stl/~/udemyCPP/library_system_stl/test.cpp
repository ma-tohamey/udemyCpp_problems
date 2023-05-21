#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int demo[5] = {5, 4, 3, 2, 1};

  sort(demo, demo + 5);

  for (int i = 0; i < 5; i++)
    cout << demo[i] << " ";
  return 0;
}
