#include <iostream>

class Person {
public:
  Person() { std::cout << "Person Constructor" << std::endl; }
  virtual void print() { std::cout << "Person" << std::endl; }
  virtual void sayHi() { std::cout << "Hello!" << std::endl; }
  virtual ~Person() { std::cout << "~Person" << std::endl; }
};

class Student : public Person {
public:
  Student() { std::cout << "Student Constructor" << std::endl; }
  void print() { std::cout << "Student" << std::endl; }
  void sayHi() { std::cout << "hi" << std::endl; }
  ~Student() { std::cout << "~Student" << std::endl; }
};

int main(int argc, char *argv[]) {

  Person *student_ptr3 = new Student;

  // student_ptr3->print(); // Person
  student_ptr3->print();
  student_ptr3->sayHi();

  delete student_ptr3;

  return 0;
}
