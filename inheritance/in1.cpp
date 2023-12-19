#include <cmath>
#include <iostream>

class Person {
public:
  std::string name = "Mostafa";
  std::string email = "most@gmail";

  bool IsValidEmailFormat() { return true; }
};

class Student : public Person {
private:
  double GPA;

public:
  void PrintGrades() { std::cout << name << " GPA= " << GPA << std::endl; }
  void SetGpa(double gpa) { GPA = gpa; }
};
