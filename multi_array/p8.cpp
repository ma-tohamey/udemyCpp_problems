#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int value, rows_cols, upper_triangular_sum = 0, lower_triangular_sum = 0;

  cin >> rows_cols;
  for (int i = 0; i < rows_cols; i++) {
    for (int j = 0; j < rows_cols; j++) {
      cin >> value;

      bool is_upper_triangular = (j >= i);
      bool is_lower_triangular = (i >= j);

      if (is_upper_triangular)
        upper_triangular_sum += value;

      if (is_lower_triangular)
        lower_triangular_sum += value;
    }
  }

  cout << upper_triangular_sum << endl;
  cout << lower_triangular_sum << endl;
  return 0;
}
