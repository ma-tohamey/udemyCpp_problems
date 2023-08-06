#include "sum.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  for (int i = 0; i < 3; ++i)
    sum_1_n(10);

  total_calls += 100;

  for (int i = 0; i < 3; ++i)
    sum_1_n(10);

  return 0;
}
