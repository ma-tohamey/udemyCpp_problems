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

  // حاسس ان الطريقه دي غبيه الافضل الطريقه اللي انا لسه مكملتهاش باختصار فيه
  // طريقه افضل من دي array direction {left diagonal up, up, right diagonal up,
  // left, right, left diagonal down, down, right diagonal down}
  int i_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int j_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int current_value = matrix[i][j];
      bool is_mountain = true;

      // comparing current value with avilable neighbours
      for (int n = 0; n < 8; n++) {
        int neighbour_i = i + i_dir[n], neighbour_j = j + j_dir[n],
            neighbour_value = matrix[neighbour_i][neighbour_j];

        bool is_avilable_neighbour = (0 <= neighbour_i && neighbour_i < rows &&
                                      0 <= neighbour_j && neighbour_j < cols);

        if (is_avilable_neighbour && neighbour_value > current_value) {
          is_mountain = false;
          break;
        }
      }

      if (is_mountain) {
        cout << i << " " << j << endl;
      }
    }
  }
  return 0;
}
