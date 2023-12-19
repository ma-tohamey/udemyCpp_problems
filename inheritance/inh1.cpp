#include <iostream>
#include <vector>

class Person {
protected:
  std::string name;
  std::string email;
  std::string address;
  std::string national_id;

public:
  bool IsValidEmailFormat() { return true; }
  void SetName(const std::string &name) { this->name = name; }
};

class Student : public Person {
private:
  int starting_study_year;
  double GPA;
  std::vector<int> studied_courses;

public:
  void AddCourseGrade(int course_id, double grade) {}
  void PrintGrades() { std::cout << name << " GPA=" << GPA << "\n"; }
  void SetGpa(double gpa) { GPA = gpa; }
};

class Teacher : public Person {
private:
  int starting_employement_year;
  double current_salary;
  std::vector<int> teaching_course;

public:
  void AddCourse(int course_id) {}
  void SetCurrentSalary(double currentSalary) {
    this->current_salary = currentSalary;
  }
};

class TeachingAssistant : public Teacher, public Student {
private:
public:
};

int main(int argc, char *argv[]) {
  Student s1;
  s1.SetName("Morad");
  s1.SetGpa(3.5);
  s1.PrintGrades();

  TeachingAssistant ta1;
  ta1.SetName("ramy ali mohsin");

  Teacher t1;
  t1.IsValidEmailFormat();
  t1.SetCurrentSalary(50000.0);
  return 0;
}
