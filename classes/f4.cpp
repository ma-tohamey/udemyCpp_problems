#include <assert.h>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

// class CourseInfo {
//   string CourseName;
//   double Grade;
//
//   CourseInfo(string CourseName, double Grade)
//       : CourseName(CourseName), Grade(Grade) {}
// };

class StudentGradesInfo {
private:
  string student_id;
  vector<double> grades;
  vector<string> courses_names;
  static int statistics_total_prints;
  const int MAX_GRADE_PER_COURSE = 100;

  double GradeChecker(double grade) {
    if (grade < 0)
      return 0;
    if (grade > MAX_GRADE_PER_COURSE)
      return MAX_GRADE_PER_COURSE;
    return grade;
  }

public:
  // StudentGradesInfo() { assert(false); }

  // thorwing an error message is better than just terminate the process
  // with assert(false);
  StudentGradesInfo() {
    throw runtime_error(
        "Cannot create StudentGradesInfo without name and student ID.");
  }

  StudentGradesInfo(string name, string student_id) : student_id(student_id) {}

  bool AddGrade(double grade, const string &course_name) {
    grade = GradeChecker(grade);

    for (int i = 0; i < (int)courses_names.size(); ++i)
      if (course_name == courses_names[i])
        return false; // already added
    grades.push_back(grade);
    courses_names.push_back(course_name);
    return true;
  }

  void PrintAllCourses() const {
    ++statistics_total_prints;

    cout << "Grades for student: " << student_id << "\n";
    for (int i = 0; i < (int)grades.size(); ++i)
      cout << "\t" << courses_names[i] << " = " << grades[i] << "\n";
  }

  pair<string, double> GetCourseGradeInfo(int pos) const {
    if (pos < 0 || pos >= (int)grades.size())
      return make_pair("", -1);
    return make_pair(courses_names[pos], grades[pos]);
  }

  string GetStudentId() const { return student_id; }

  int GetTotalCoursesCount() const { return grades.size(); }

  // Use GetTotalCoursesCount for naming consistency
  // pair<double, double> get_total_gradesSum() {
  pair<double, double> GetTotalGradesSum() const {
    double StudentGrade = 0, FullGrade = 0;
    for (int i = 0; i < (int)grades.size(); ++i)
      StudentGrade += grades[i], FullGrade += MAX_GRADE_PER_COURSE;
    return make_pair(StudentGrade, FullGrade);
  }
};

int StudentGradesInfo::statistics_total_prints = 0;

int main() {
  // StudentGradesInfo st1;
  // std::cout << st1.GetStudentId() << std::endl;

  StudentGradesInfo st1("Mostafa", "S000123");
  st1.AddGrade(70, "Math");
  st1.AddGrade(70, "programming 1");
  st1.AddGrade(85, "programming 2");

  st1.PrintAllCourses();
  cout << st1.GetStudentId() << endl;
  cout << st1.GetTotalCoursesCount() << endl;
  cout << st1.GetCourseGradeInfo(1).first << " / "
       << st1.GetCourseGradeInfo(1).second << endl;

  // pair<double, double> p = st1.get_total_gradesSum();
  pair<double, double> p = st1.GetTotalGradesSum();
  cout << p.first << "/" << p.second << "\n";

  cout << "Bye\n";

  // StudentGradesInfo st2("Mastafa", "S000123");
  // st2.AddGrade(-129, "Math");
  // st2.AddGrade(70, "programming 1");
  // st2.AddGrade(85, "programming 2");
  //
  // st2.PrintAllCourses();
  //
  // pair<double, double> p2 = st2.get_total_gradesSum();
  // cout << p2.first << "/" << p2.second << "\n";
  //
  // cout << "Bye\n";
  //
  return 0;
}
