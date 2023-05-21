#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int *p1{new int{20}};
  *p1 = 20;
  int *p2{p1};

  return 0;
}
