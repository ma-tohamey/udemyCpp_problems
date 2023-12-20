#include <iostream>

class Person {
public:
  virtual void print() const { std::cout << "Person\n"; }
  virtual ~Person() { std::cout << "~Person\n"; }
};

class Student : public Person {
public:
  virtual void print() const override { std::cout << "Student\n"; }
  virtual ~Student() override { std::cout << "~Student\n"; }
};

int main(int argc, char *argv[]) {
  Person person;
  Student stud;

  person.print();
  stud.print();

  Person *per_ptr = &person;
  Student *stud_ptr1 = &stud;

  Person *stud_ptr2 = &stud;
  Person *stud_ptr3 = new Student;

  per_ptr->print();
  stud_ptr1->print();
  stud_ptr2->print();
  stud_ptr3->print();

  delete stud_ptr3;
  return 0;
}
