#include <iostream>
using namespace std;

struct Employee {
  string name;
  int *id = nullptr;

  Employee(int id_, string name_) {
    name = name_;
    id = new int{id_};
  }

  ~Employee() {
    cout << "Bye\n";
    if (id != nullptr)
      delete id;
    id = nullptr;
  }

  void print() { cout << *id << " " << name << " "; }

  void set_nulls() { id = nullptr; }
};

int main() {
  Employee *e1{new Employee(20, "belal")};

  e1->print();

  Employee *e2(e1);

  Employee e3{*e1};

  e2->print();

  std::cout << std::endl;

  std::cout << e1 << ' ' << e2 << ' ' << &e3 << std::endl;

  e3.set_nulls();
  delete e1;

  return 0;
}
