#include "employee.h"
#include <iostream>
using namespace std;

int main() {
  // Employee e("Mostafa");
  glob_emp->print();

  Employee new_emp("mahmoud");
  new_emp.print();

  delete glob_emp;
  return 0;
}
