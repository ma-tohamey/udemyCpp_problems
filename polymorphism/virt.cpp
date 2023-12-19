#include <iostream>

class Person {
public:
  Person() { std::cout << "Person init\n"; }
  /* virtual */ void print() { std::cout << "Person\n"; }
  /* virtual */ ~Person() { std::cout << "~Person\n"; }
};
class Student : public Person {
public:
  Student() { std::cout << "Student init\n"; }
  void print() { std::cout << "Student\n"; }
  ~Student() { std::cout << "~Student\n"; }
};

int main(int argc, char *argv[]) {
  Person *perPtr = new Student;
  perPtr->print();
  delete perPtr;

  // Student student;
  // Person &person = student;
  // person.print();

  return 0;
}
