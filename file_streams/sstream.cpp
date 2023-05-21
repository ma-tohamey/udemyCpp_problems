#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  ifstream file_hanler("read_file.txt");
  ofstream tmp("tmp.txt");

  string line;

  while (getline(file_hanler, line)) {
    istringstream iss(line);
    string line_num, phone_number;
    iss >> line_num >> phone_number;
    if (line_num == "4") {
      phone_number += " That was my old ets number";
      tmp << line_num << ' ' << phone_number << endl;
    }
    tmp << line << endl;
  }

  file_hanler.close();
  tmp.close();
  remove("read_file.txt");
  rename("tmp.txt", "read_file.txt");

  // while (getline(file_hanler, line)) {
  //   istringstream iss(line);
  //   // int line_num;
  //   string phone_number;
  //   // iss >> line_num >> phone_number;
  //   // phone_number = "my mom's number";
  //   line.replace(line.find(line), line.size(), "");
  // }
  // ostringstream oss;
  // oss << "Mostafa ";
  // oss << 50;
  // oss << " years old" << endl;
  //
  // cout << oss.str() << endl;
  //
  // string str = "mahmoud 23 years";
  // istringstream ss(str);
  //
  // string n, u;
  // int y;
  //
  // ss >> n >> y >> u;
  // cout << n << ' ' << y << ' ' << u << endl;

  return 0;
}
