#include <iostream>

using namespace std;

int main() {
  int const MAX = 100;
  int matrix[MAX][MAX];

  int rows, cols, max_i, max_j, max_value;
  cin >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];

      bool first_time = (i == 0 && j == 0);
      if (first_time) {
        max_value = matrix[i][j];
        max_i = i;
        max_j = j;
      } else {
        if (matrix[i][j] >= max_value) {
          max_value = matrix[i][j];
          max_i = i;
          max_j = j;
        }
      }
    }
  }
  cout << "Max value at position " << max_i << " " << max_j
       << " with value = " << max_value << endl;
  return 0;
}
