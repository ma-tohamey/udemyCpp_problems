#include <iostream>

class Person {
private:
  std::string name = "mostafa";
  std::string email = "mostafa@gmail.com";

protected: // that's way we have protected access modifire
  const std::string &getName() const { return name; }

public:
  bool IsValidEmail() { return true; }
};

class Student : public Person {
private:
  double GPA;

public:
  void PrintGrades() { std::cout << getName() << ; }
};
