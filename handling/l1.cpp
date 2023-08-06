#include <iostream>

struct Name {
  std::string first;
  Name() {}
  Name(std::string _first) { first = _first; }
  ~Name() { std::cout << "Name Destructor " << first << std::endl; }
};

struct Employee {
  Name *full_name1{};
  Name full_name2;

  Employee() {
    full_name1 = new Name("mostafa");
    // throw 0;
    full_name2.first = "belal";
  }
  ~Employee() {
    delete full_name1;
    std::cout << "Destroy Employee" << std::endl;
  }
};

int main(int argc, char *argv[]) {
  try {
    Employee();
  } catch (...) {
  }
  return 0;
}
