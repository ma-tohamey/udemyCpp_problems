#include <iostream>

class Employee {
private:
  int *salary{nullptr};
  std::string name;

public:
  Employee() = default;

  Employee(double salary, std::string name) = delete;

  Employee(int salary, std::string name)
      : salary(new int{salary}), name(name){};

  Employee &operator=(const Employee &) = delete;

  ~Employee() {
    delete salary;
    salary = nullptr;
  }
};

int main(int argc, char *argv[]) {

  Employee e1(10, "mostafa");
  Employee e2;
  // Employee e2(10.5, "mostafa");
  e2 = e1;

  return 0;
}
