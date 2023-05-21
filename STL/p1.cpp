#include <iostream>
#include <queue>
using namespace std;

struct last_k_numbers_sum_stream {
  int k;
  int sum = 0;
  queue<int> k_numbers;

  last_k_numbers_sum_stream(int _k) { k = _k; }

  int next(int new_num) {
    k_numbers.push(new_num);
    sum += new_num;
    if ((int)k_numbers.size() > k) {
      cout << "the first element is: " << k_numbers.back() << endl;
      sum -= k_numbers.front();
      k_numbers.pop();
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  int num;
  last_k_numbers_sum_stream processor(4);
  while (cin >> num) {
    cout << processor.next(num) << endl;
  }
  return 0;
}
