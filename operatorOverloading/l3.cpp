#include <iostream>

class Employee {
public:
  int id;
  int salary;
  std::string name;

  Employee(int id, int salary, std::string name)
      : id(id), salary(salary), name(name) {}

  bool operator<(const Employee &other) {
    return std::tie(id, salary, name) <
           std::tie(other.id, other.salary, other.name);
  }
};

int main(int argc, char *argv[]) {
  Employee e1(1, 2500, "mahmoud");
  Employee e2(2, 3500, "ramy");

  std::cout << (e1 < e2) << std::endl;
  return 0;
}
