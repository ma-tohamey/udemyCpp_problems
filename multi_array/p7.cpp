#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int const MAX = 100;
  int matrix[MAX][MAX];
  int rows, cols, query, st_row, nd_row;

  cin >> rows >> cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }

  cin >> query;
  for (int i = 0; i < query; i++) {
    cin >> st_row >> nd_row;
    st_row -= 1, nd_row -= 1;
    string result = "YES";

    for (int col = 0; col < cols; col++) {
      if (matrix[st_row][col] > matrix[nd_row][col]) {
        result = "NO";
        break;
      }
    }
    cout << result << endl;
  }
  return 0;
}
