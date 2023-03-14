#include <iostream>
using namespace std;

struct full_name {
  string first, middle, last;

  // full_name() {
  //   first = middle = last = "";
  //   // do some operations
  // }

  // full_name(string _first, string _last = "") {
  //   first = _first;
  //   last = _last;
  //   middle = "";
  // }

  full_name(string _first = "", string _last = "") {
    first = _first;
    last = _last;
  }
};

int main(int argc, char *argv[]) {
  full_name chossen_emp;
  full_name first_person("mahmoud");
  // first_person.first = "mahmoud";
  cout << first_person.first << endl;

  full_name my_name = full_name("ali");
  cout << my_name.first << "\n";

  full_name his_name = full_name("mostafa", "ibrahim");
  cout << his_name.last << endl;
  return 0;
}
