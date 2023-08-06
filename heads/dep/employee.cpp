#include "employee.h"
#include "department.h"

Employee *glob_emp = new Employee("mostafa");

Employee::Employee(string _name) { name = _name; }

void Employee::print() {
  cout << "I am " << name << endl;

  cout << "I work in the following departments: " << endl;

  for (Department *d : deps)
    d->printDepartment();
}
