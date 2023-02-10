#include <iostream>

using namespace std;

int main() {
  int const MAX = 100;
  int array_1D[MAX], array_2D[MAX][MAX], rows, cols, idx;
  cin >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> array_2D[i][j];
      idx = i * cols + j;
      array_1D[idx] = array_2D[i][j];
    }
  }

  for (int i = 0; i <= idx; i++) {
    cout << array_1D[i] << " ";
  }
  cout << endl;
  return 0;
}
