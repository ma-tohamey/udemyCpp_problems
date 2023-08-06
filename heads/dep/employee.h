#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <vector>
using namespace std;

struct Department;

struct Employee {
  string name;
  vector<Department *> deps;

  Employee(string _name);
  void print();
};

#endif // !DEBUG
