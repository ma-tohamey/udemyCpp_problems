#include <iostream>

class Person {
protected:
  std::string name;
};

class Student : public Person {
protected:
  std::string student_id;
};

class Graduate : public Student {
protected:
  int graduation_year;

public:
  void reset() { name = student_id = ""; }
};
