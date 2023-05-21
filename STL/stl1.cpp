#include <iostream>
#include <queue>
using namespace std;

struct last_k_numbers_sum_stream {
  int k, sum;
  queue<int> q;
  last_k_numbers_sum_stream(int _k) {
    sum = 0;
    k = _k;
  }

  int next(int new_number) {
    sum += new_number;
    q.push(new_number);
    if (q.size() > k) {
      sum -= q.front();
      q.pop();
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  last_k_numbers_sum_stream processor(4);
  int num;
  while (cin >> num)
    cout << processor.next(num) << endl;
  return 0;
}
