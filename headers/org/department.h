#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "employee.h"

struct Department {
  string name;
  vector<employee> deps;

  void printDepartment();
};

#endif // !DEPARTMENT_H_
