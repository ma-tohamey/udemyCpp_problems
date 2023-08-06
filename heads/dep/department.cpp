#include "department.h"

void Department::printDepartment() {
  cout << "Department name " << name << " has " << deps.size() << " Employees"
       << endl;
}
