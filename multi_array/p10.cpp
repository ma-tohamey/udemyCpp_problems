#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int const MAX = 100;
  bool primes[MAX][MAX];
  int rows, cols, value;

  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> value;

      bool is_prime = true;
      for (int k = 2; k < value; k++) {
        bool not_prime = (value % k == 0);
        if (not_prime) {
          is_prime = false;
          break;
        }
      }
      primes[i][j] = is_prime;
    }
  }

  int query, start_i, start_j, end_i, end_j;
  cin >> query;

  for (int q = 0; q < query; q++) {
    cin >> start_i >> start_j >> end_i >> end_j;
    end_i += start_i - 1, end_j += start_j - 1;
    int prime_couter = 0;

    for (; start_i <= end_i; start_i++) {
      for (int j = start_j; j <= end_j; j++) {
        if (primes[start_i][j]) {
          prime_couter++;
        }
      }
    }
    cout << prime_couter << endl;
  }
  return 0;
}
