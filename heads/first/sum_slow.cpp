#include "sum.h"
#include <iostream>
using namespace std;

int total_calls = 0;
int sum_1_n(int n) {
  ++total_calls;

  cout << "total_calls " << total_calls << endl;
  int sum = 0;

  for (int i = 0; i < n; ++i)
    sum += i;

  return sum;
}
