#include <iostream>
using namespace std;

int main() {
  int const MAX = 100;
  int matrix[MAX][MAX];

  int rows, cols, sum_left_dia = 0, sum_right_dia = 0, sum_last_row = 0,
                  sum_last_col = 0;

  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      bool is_left_dia = (i == j);
      bool is_right_dia = (j == cols - 1);
      bool is_last_row = (i == rows - 1);
      bool is_last_col = (j == cols - 1);
      cin >> matrix[i][j];

      if (is_left_dia) {
        sum_left_dia += matrix[i][j];
      }

      if (is_right_dia) {
        sum_right_dia += matrix[i][(cols - 1) - i];
      }

      if (is_last_row) {
        sum_last_row += matrix[i][j];
      }

      if (is_last_col) {
        sum_last_col += matrix[i][j];
      }
    }
  }

  cout << sum_left_dia << " " << sum_right_dia << "\n";
  cout << sum_last_row << " " << sum_last_col << endl;
  return 0;
}
