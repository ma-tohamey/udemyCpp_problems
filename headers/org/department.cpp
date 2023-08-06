#include "department.h"

void Department::printDepartment() {
  cout << "Department name is: " << name << " has " << deps.size()
       << " Employees" << endl;
}
