#include <iostream>
using namespace std;

int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS) {
  if (row >= ROWS || col >= COLS)
    return 0;

  int i_dir[3] = {0, 1, 1};
  int j_dir[3] = {1, 1, 0};
  int max_neighbour = grid[row + i_dir[0]][col + j_dir[0]];
  int new_row, new_col, max_idx = 0;

  for (int i = 1; i < 3; i++) {
    new_row = row + i_dir[i], new_col = col + j_dir[i];

    if (grid[new_row][new_col] > max_neighbour) {
      max_neighbour = grid[new_row][new_col];
      max_idx = i;
    }
  }
  new_row = row + i_dir[max_idx], new_col = col + j_dir[max_idx];

  return grid[row][col] + path_sum(grid, new_row, new_col, ROWS, COLS);
}

int main(int argc, char *argv[]) {
  int arr[100][100], rows, cols;
  cin >> rows >> cols;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cin >> arr[i][j];

  cout << endl;

  cout << path_sum(arr, 0, 0, rows, cols) << endl;
  return 0;
}
