#include <iostream>
using namespace std;
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

struct Employee {
  string name;

  Employee(string _name);
  void print();
  void sayHello();
};

extern Employee *emp;
// extern Employee emp;
// extern Employee &emp;

#endif // !DEBUG
