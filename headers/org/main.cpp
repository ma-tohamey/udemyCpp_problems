#include "department.h"
#include "employee.h"
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// struct department;
//
// struct employee {
//   string name;
//   vector<department *> deps;
//
//   employee(string _name) { name = _name; }
//   void print();
// };

int main(int argc, char *argv[]) {
  Department production;
  production.name = "production";
  production.deps.push_back(*emp_glob);
  emp_glob->deps.push_back(&production);
  emp_glob->print();
  return 0;
}
