#include <chrono>
#include <iostream>
#include <ratio>

using namespace std::chrono;
using namespace std;

int main() {
  int const N = 1000;
  bool sequence[N] = {0};
  int n, ones = 0, zeros = 0, least = 1, max_idx = 0, current_idx = 0,
         current_max_seq = 0, max_sequence = 0, seperator = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sequence[i];
    if (sequence[i] == true) {
      ones++;
    } else {
      zeros++;
    }
  }

  auto start = high_resolution_clock::now();
  if (ones > zeros) {
    least = 0;
  }

  for (int i = 0; i < n; i++) {
    if (sequence[i] == least) {
      current_idx = i;
      current_max_seq++;
      seperator = 0;
      if (current_max_seq > max_sequence) {
        max_sequence = current_max_seq;
        max_idx = current_idx;
      }
    } else {
      seperator++;
      if (seperator >= 3) {
        seperator = 0;
        if (current_max_seq > max_sequence) {
          max_sequence = current_max_seq;
          max_idx = current_idx;
        } else {
          current_max_seq = 0;
        }
      }
    }
  }

  max_idx++;
  int length_longest_sequence = max_sequence * 2;

  if (length_longest_sequence > max_idx) {
    max_idx += length_longest_sequence - max_idx;
  }

  int start_idx = max_idx - length_longest_sequence;

  cout << length_longest_sequence << "\n";
  for (; start_idx < max_idx; start_idx++) {
    cout << sequence[start_idx] << " ";
  }
  cout << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function: " << duration.count() << " microseconds"
       << endl;
  return 0;
}
