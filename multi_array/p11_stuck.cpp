#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int const MAX = 100;
  int matrix[MAX][MAX], rows, cols;

  cin >> rows >> cols;
  // reading matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }

  // find mountains
  int current_i = 0, current_j = 0, current_value;
  // array direction {left diagonal up, up, right diagonal up, left, right, left
  // diagonal down, down, right diagonal down}
  int i_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int j_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  while (current_i < rows && current_j < cols) {
    current_value = matrix[current_i][current_j];
    bool is_mountain = true;

    // comparing current value with avilable neighbours
    for (int i = 0; i < 8; i++) {
      int neighbour_i = current_i + i_dir[i],
          neighbour_j = current_j + j_dir[i],
          neighbour_value = matrix[neighbour_i][neighbour_j];

      bool is_avilable_neighbour = (0 <= neighbour_i && neighbour_i < rows &&
                                    0 <= neighbour_j && neighbour_j < cols);

      if (is_avilable_neighbour && neighbour_value > current_value) {
        is_mountain = false;
        current_i = neighbour_i, current_j = neighbour_j;
        break;
      }
    }

    if (is_mountain) {
      cout << current_i << " " << current_j << endl;

      if (current_j + 2 < cols) {
        current_j += 2;
        continue;
      }

      if (current_i + 2 < rows) {
        current_i += 2;
        current_j = 0;
        continue;
      }
    }
  }
  return 0;
}
