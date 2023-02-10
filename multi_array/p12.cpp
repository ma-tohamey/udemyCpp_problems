#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int rows, cols, query, direction, steps;
  cin >> rows >> cols >> query;

  int i_dir[] = {-1, 0, 1, 0};
  int j_dir[] = {0, 1, 0, -1};

  int current_i = 0, current_j = 0;
  for (int q = 0; q < query; q++) {
    cin >> direction >> steps;

    current_i += (steps % rows) * i_dir[direction - 1];
    current_j += (steps % cols) * j_dir[direction - 1];

    if (current_i < 0) {
      current_i += rows;
    }
    if (current_j < 0) {
      current_j += cols;
    }
    cout << "(" << current_i << "," << current_j << ")" << endl;
  }

  return 0;
}
