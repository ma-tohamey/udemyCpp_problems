#include "employee.h"

namespace OurSystem {
Employee *glob_emp = new Employee("mostafa");
Employee::Employee(std::string _name) { name = _name; }
void Employee::print() { std::cout << "I am " << name << std::endl; }
} // namespace OurSystem
