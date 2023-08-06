#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "employee.h"
#include <vector>

struct Department {
  string name;
  vector<Employee> deps;

  void printDepartment();
};

#endif // !DEBUG
