#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
using namespace std;

struct Employee {
  string name;

  Employee(string _name);
  void print();
};

extern Employee *glob_emp;

#endif
