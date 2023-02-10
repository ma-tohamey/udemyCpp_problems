#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int const MAX = 100;
  int normal_matrix[MAX][MAX];
  int compose_matrix[MAX][MAX];
  int rows, cols, value;

  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> value;
      normal_matrix[i][j] = value;
      compose_matrix[j][i] = value;
    }
  }

  cout << endl;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << normal_matrix[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      cout << compose_matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
