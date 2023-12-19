#include <iostream>

class Person /*final*/ {
  // protected:
  //   std::string name;

public:
  std::string name;
  Person() : name("most") { std::cout << "Person Default Constructor\n"; }

  Person(std::string name) : name(name) {
    std::cout << "Person 2nd Constructor\n";
  }

  ~Person() { std::cout << "Person Destructor\n"; }
};

class Student : public Person {
private:
  double gpa;

public:
  // using Person::Person;
  Student() : name(name) {
    std::cout << "Student Default Constructor\n";
    gpa = 0;
    name = "hani";
  }

  Student(double gpa) : Person(), gpa(gpa) {
    std::cout << "Student 2nd Constructor\n";
  }

  ~Student() { std::cout << "Student Destructor\n"; }
};
int main(int argc, char *argv[]) {
  Student student1;
  Student student2(3.0);
  return 0;
}
