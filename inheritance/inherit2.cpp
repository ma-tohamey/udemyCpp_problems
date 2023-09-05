#include <iostream>
#include <vector>

class Student {
protected:
  double gpa;
};

class Employee {
protected:
  double salary;
};

// that's what we call multilevel inheritance
class TeachingAssistance : public Student, public Employee {
private:
  std::vector<int> courses_ids;

  void func() {
    gpa = 3.5;
    salary = 5000.0;
  }
};
