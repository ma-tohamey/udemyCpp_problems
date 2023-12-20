#include <iostream>
#include <vector>
using namespace std;

class ChessBoard {
private:
  int rows;
  int colums;
  vector<vector<int>> board;

public:
  ChessBoard(int rows, int colums) : rows(rows), colums(colums) {
    board = vector<vector<int>>(rows, vector<int>(colums));
  }

  int &operator()(int row, int col) { return board[row][col]; }
  std::vector<int> &operator[](int pos) { return board[pos]; }
};

int main() {
  ChessBoard board(2, 3); // 2x3 grid

  board(0, 0) = 10;
  board[0][1] = 20;

  cout << board[0][0] << " " << board(0, 1);

  return 0;
}
