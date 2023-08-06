#include <iostream>

class Employee {
private:
  std::string name;

public:
  Employee(std::string name) : name(name) {
    std::cout << "Constructor: " << name << std::endl;
  }

  ~Employee() { std::cout << "Destructor: " << name << std::endl; }
};

int main(int argc, char *argv[]) {
  static Employee belal("Belal");

  Employee most("Mostafa");

  if (true)
    Employee("Mona");

  static Employee Asmaa("Asmaa");
  return 0;
}
