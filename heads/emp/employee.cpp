#include "employee.h"

Employee *glob_emp = new Employee("mostafa");

Employee::Employee(string _name) { name = _name; }
void Employee::print() { cout << "I am " << name << endl; }
