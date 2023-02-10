#include <iostream>

using namespace std;

int main() {
  int const MAX = 100;
  int matrix[MAX][MAX];

  int rows, cols, tmp, st_col, nd_col;
  cin >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }

  cin >> st_col >> nd_col;

  for (int i = 0; i < rows; i++) {
    tmp = matrix[i][st_col];
    matrix[i][st_col] = matrix[i][nd_col];
    matrix[i][nd_col] = tmp;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
