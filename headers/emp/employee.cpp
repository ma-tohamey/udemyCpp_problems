#include "Employee.h"

Employee *emp = new Employee("mostafa");

// Employee emp("mostafa");

// Employee e("mahmoud");

Employee::Employee(string _name) { name = _name; }
void Employee::print() { cout << "I am " << name << endl; }
void Employee::sayHello() { cout << name << " is saying Hello! " << endl; }
