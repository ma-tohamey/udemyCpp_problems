#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>

namespace OurSystem {
struct Employee {
  std::string name;

  Employee(std::string _name);
  void print();
};
extern Employee *glob_emp;
} // namespace OurSystem

#endif // !DEBUG
