#include <iostream>
#include <vector>

// class Employee {
// private:
//   // static int i;
//   std::string name;
//   static int employee_count;
//
// public:
//   Employee(std::string name) : name(name) { ++Employee::employee_count; }
//   static int GetEmployeeCount() { return Employee::employee_count; }
//
//   // Employee() { Employee::i++; }
// };
//
// int Employee::employee_count = 0;
// int Employee::i = 0;
//
class A {};

class B {
public:
  int f;
  B(int a, int b) { f = 10; }
};

class C {
public:
  static std::vector<int> v;
  static int arr[10];
  static A a;
  static B b;
};

std::vector<int> C::v = std::vector<int>(20);
int C::arr[10];
A C::a;
// B C::b = B(1, 2);

int main(int argc, char *argv[]) {
  // std::cout << C::b.f << std::endl;
  // code
  // Employee most("mostafa");
  // Employee rost("mostafa");
  // Employee nost("mostafa");
  // Employee kost("mostafa");
  // std::cout << Employee::GetEmployeeCount() << std::endl;

  // Employee e;
  // std::cout << Employee::i << std::endl;
  return 0;
}
