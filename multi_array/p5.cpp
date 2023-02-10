#include <iostream>

using namespace std;

int main() {
  int const MAX = 100;
  int matrix[MAX][MAX];

  int rows, cols;
  cin >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }

  int i_dir[3] = {0, 1, 1};
  int j_dir[3] = {1, 1, 0};

  int current_rob_i = 0, current_rob_j = 0, sum = 0;

  while (current_rob_i < rows && current_rob_j < cols) {
    sum += matrix[current_rob_i][current_rob_j];
    int max_i, max_j, max_neighbour;

    for (int i = 0; i < 3; i++) {
      int neighbour_i = current_rob_i + i_dir[i];
      int neighbour_j = current_rob_j + j_dir[i];
      int current_neighbour = matrix[neighbour_i][neighbour_j];
      bool first_time = (i == 0);

      if (first_time || current_neighbour > max_neighbour) {
        max_i = neighbour_i;
        max_j = neighbour_j;
        max_neighbour = current_neighbour;
      }
    }

    current_rob_i = max_i;
    current_rob_j = max_j;
  }

  cout << sum << endl;
  return 0;
}
