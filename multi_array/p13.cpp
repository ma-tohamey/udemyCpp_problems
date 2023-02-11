#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int deapth, rows, cols, convert_method;
  cin >> deapth >> rows >> cols >> convert_method;

  // convert from 3d to 1d idx
  if (convert_method == 1) {
    int target_depth, target_row, target_col;
    cin >> target_depth >> target_row >> target_col;
    int idx = ((target_depth * rows * cols) + (target_row * cols) + target_col);
    cout << idx << endl;
  }

  // convert from 1d to 3d idx
  if (convert_method == 2) {
    int index, target_depth, target_row, target_col;
    cin >> index;

    target_depth = index / (rows * cols);
    // target_row = index % rows;
    target_row = (index % (rows * cols) / (rows * cols));
    // target_col = index % cols;
    target_col = (index % (rows * cols) % (rows * cols));

    cout << target_depth << " " << target_row << " " << target_col << endl;
  }
  return 0;
}
