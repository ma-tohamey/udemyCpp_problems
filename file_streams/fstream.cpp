#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  ifstream rfile_handler("read_file.txt");
  ofstream ofile_handler("output.txt", ios::app);

  if (rfile_handler.fail()) {
    cout << "Can't open the file" << endl;
    return 0;
  }

  if (ofile_handler.fail()) {
    cout << "Can't open the output file" << endl;
    return 0;
  }

  string line;
  while (getline(rfile_handler, line))
    ofile_handler << line << endl;

  rfile_handler.close();
  ofile_handler.close();
  // bool append = true;
  // auto status = ios::in | ios::out | ios::app;
  //
  // if (!append)
  //   status = ios::in | ios::out | ios::trunc;
  //
  // fstream file_handler("read_file.txt", status);
  //
  // if (file_handler.fail()) {
  //   cout << "Can't open the file" << endl;
  //   return 0;
  // }
  //
  // string first, second;
  // file_handler >> first >> second;
  //
  // cout << first << ' ' << second << endl;
  //
  // file_handler.clear();
  //
  // file_handler << "atef\n";
  //
  // file_handler.close();

  // ifstream rfile_handler("read_file.txt");
  // if (rfile_handler.fail()) {
  //   cout << "Can't open the file" << endl;
  //   return 0;
  // }
  //
  // int x, y;
  // rfile_handler >> x >> y;
  // cout << x + y << endl;
  //
  // rfile_handler.close();
  //
  // ofstream fout("output.txt");
  //
  // if (fout.fail()) {
  //   cout << "Can't opent the output file" << endl;
  //   return 0;
  // }
  //
  // fout << x + y << endl;
  // fout.close();

  // freopen("read_file.txt", "rt", stdin);
  //
  // int x, y;
  // cin >> x >> y;
  //
  // cout << x + y << endl;

  // freopen("output_file.txt", "wt", stdout);

  return 0;
}
