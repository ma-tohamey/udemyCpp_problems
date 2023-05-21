#include <iostream>
#include <vector>
using namespace std;

void print_3d_vector(vector<vector<vector<int>>> &v3d) {
  for (auto cell : v3d) {
    for (auto row : cell) {
      for (auto col : row)
        cout << col << " ";
      cout << endl;
    }
  }
}
int main(int argc, char *argv[]) {
  // vector<int> st_col(4, 1);
  // vector<vector<int>> st_row(3, st_col);
  //
  // vector<int> nd_col(4, 2);
  // vector<vector<int>> nd_row(3, nd_col);
  //
  // vector<int> rd_col(4, 3);
  // vector<vector<int>> rd_row(3, rd_col);
  //
  // vector<int> th_col(4, 4);
  // vector<vector<int>> th_row(3, th_col);
  //
  // vector<vector<vector<int>>> v3d(4);
  // v3d[0] = st_row;
  // v3d[1] = nd_row;
  // v3d[2] = rd_row;
  // v3d[3] = th_row;
  //
  vector<vector<vector<int>>> v3d(4, vector<vector<int>>(3, vector<int>(4, 1)));

  print_3d_vector(v3d);

  return 0;
}
