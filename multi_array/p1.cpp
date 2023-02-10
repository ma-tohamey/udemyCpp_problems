#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int idx = 0;
  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 4; ++col) {
      cout << "index " << idx << " has r,c = " << row << " " << col << "\n";
      ++idx;
    }
  }
  return 0;
}
