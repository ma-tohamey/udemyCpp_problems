#include "employee.h"
#include "department.h"

employee *emp_glob = new employee("mostafa");

employee::employee(string _name) { name = _name; }
void employee::print() {
  cout << "i am " << name << endl;
  cout << "i work in the following departments: " << endl;
  for (Department *d : deps)
    d->printDepartment();
}
