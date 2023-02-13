#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int const MAX = 100;
  char matrix[MAX][MAX], player = 'X', winner;
  bool no_winner = true;
  int rows_cols, role_counter = 0;
  cin >> rows_cols;

  for (int i = 0; i < rows_cols; i++) {
    for (int j = 0; j < rows_cols; j++) {
      matrix[i][j] = '.';
    }
  }

  while (no_winner) {
    if (role_counter > (rows_cols * rows_cols)) {
      cout << "Game Is Over\nTie. There is no winner" << endl;
      break;
    }

    cout << "Player " << player << " turn. Enter empty location (r, c): ";
    int row_idx, col_idx;
    cin >> row_idx >> col_idx;
    row_idx--, col_idx--;

    // validate user input
    bool is_out_boundries = (0 > row_idx && row_idx >= rows_cols) &&
                            (0 > col_idx && col_idx >= rows_cols);
    bool is_taken = (matrix[row_idx][col_idx] != '.');

    if (is_out_boundries || is_taken) {
      cout << "Invalid input. Try again" << endl;
      continue;
    }

    // valid role
    role_counter++;
    matrix[row_idx][col_idx] = player;

    // check if there is a winner
    if (role_counter >= (rows_cols * 2 - 1)) {
      for (int i = 0; i < rows_cols; i++) {
        for (int j = rows_cols - 1; j >= 0; j--) {

          if (i > 0) {
            j = 0;
          }

          // check left diagonal
          if (j == rows_cols - 1 && no_winner) {
            for (int w = 0, tmp_i = i, tmp_j = j; w < rows_cols;
                 tmp_i++, tmp_j--, w++) {
              if (matrix[tmp_i][tmp_j] == player) {
                no_winner = false;
                winner = player;
              } else {
                no_winner = true;
                break;
              }
            }
          }

          // check all down
          if (j >= i && no_winner) {
            for (int w = 0, tmp_i = i, tmp_j = j; w < rows_cols; w++, tmp_i++) {
              if (matrix[tmp_i][tmp_j] == player) {
                no_winner = false;
                winner = player;
              } else {
                no_winner = true;
                break;
              }
            }
          }

          // check right diagonal
          if (i == j && no_winner) {
            for (int w = 0, tmp_i = i, tmp_j = j; w < rows_cols;
                 w++, tmp_i++, tmp_j++) {
              if (matrix[tmp_i][tmp_j] == player) {
                no_winner = false;
                winner = player;
              } else {
                no_winner = true;
                break;
              }
            }
          }

          // check all right
          if (i >= j && no_winner) {
            for (int w = 0, tmp_i = i, tmp_j = j; w < rows_cols; w++, tmp_j++) {
              if (matrix[tmp_i][tmp_j] == player) {
                no_winner = false;
                winner = player;
              } else {
                no_winner = true;
                break;
              }
            }
          }
        }
      }
    }

    // printing gameboard
    for (int i = 0; i < rows_cols; i++) {
      for (int j = 0; j < rows_cols; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

    // change player
    if (player == 'X') {
      player = 'O';
    } else {
      player = 'X';
    }
  }

  cout << "Player " << winner << " won" << endl;

  return 0;
}
