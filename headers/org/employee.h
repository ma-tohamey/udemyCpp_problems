#ifndef DEP_H_
#define DEP_H_
#include <iostream>
#include <vector>
using namespace std;

struct Department;

struct employee {
  string name;
  vector<Department *> deps;

  employee(string _name);
  void print();
};
extern employee *emp_glob;

#endif // !DEBUG
