#include <iostream>

class Person {
public:
  virtual void print() { std::cout << "Person\n"; }
  virtual ~Person() { std::cout << "~Person\n"; }
};

class Student : public Person {
public:
  void print() { std::cout << "Student\n"; }
  ~Student() { std::cout << "~Student\n"; }
};

int main(int argc, char *argv[]) {
  Person *stud_ptr3 = new Student();
  stud_ptr3->print();
  stud_ptr3->Person::print();

  delete stud_ptr3;
  return 0;
}
