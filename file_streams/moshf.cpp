#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream fin("read_file.txt");

  vector<string> data;
  while (!fin.eof()) {
    string line;
    fin >> line;
    data.push_back(line);
  }
  // while (fin >> line) {
  //   data.push_back(line);
  // }

  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << endl;
  }

  fin.close();
  return 0;
}
