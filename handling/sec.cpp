#include <iostream>
#include <stdexcept>

struct Employee {
  int id;
  Employee(int _id) { id = _id; }
  ~Employee() { std::cout << "Destroy Employee " << id << std::endl; }
};

void f4() {
  std::cout << "start f4" << std::endl;
  Employee *p = new Employee(4);
  throw 1;
  delete p;
  std::cout << "end f4" << std::endl;
}

void f3() {
  std::cout << "start f3" << std::endl;
  Employee p(3);
  f4();
  std::cout << "end f3" << std::endl;
}

void f2() {
  std::cout << "start f2" << std::endl;
  try {
    f3();
  }
  // catch (int &error) {
  //   std::cout << "the error code is : " << error << std::endl;
  // }
  catch (std::runtime_error &error) {
    std::cout << "runtime_error: " << error.what() << std::endl;
  }
  std::cout << "end f2" << std::endl;
}

void f1() {
  std::cout << "start f1" << std::endl;
  try {
    f2();
  } catch (std::invalid_argument &error) {
    std::cout << "invalid_argument" << std::endl;
  }
  // catch (int &error) {
  //   std::cout << "error code: " << error << std::endl;
  // }
  std::cout << "end f1" << std::endl;
}

int main(int argc, char *argv[]) {
  f1();
  return 0;
}
