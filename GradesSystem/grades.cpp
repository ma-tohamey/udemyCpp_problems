#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class StudentGradesInfo {
private:
  string student_id;
  vector<double> grades;
  vector<string> courses_names;
  static int statistics_total_prints;
  const int MAX_GRADE_PER_COURSE = 100.00;

  double ValidateGrade(int grade) const {
    if (grade < 0)
      return 0;
    if (grade > MAX_GRADE_PER_COURSE)
      return MAX_GRADE_PER_COURSE;
    return grade;
  }

public:
  StudentGradesInfo(string student_id_) { student_id = student_id_; }

  bool AddGrade(double grade, string course_name) {
    grade = ValidateGrade(grade);

    for (int i = 0; i < (int)courses_names.size(); ++i)
      if (course_name == courses_names[i])
        return false; // already added
    courses_names.push_back(course_name);
    grades.push_back(grade);
    return true;
  }
  void PrintAllCourses() const {
    ++statistics_total_prints;

    cout << "Grades for student: " << GetStudentId() << "\n";
    for (int i = 0; i < (int)grades.size(); ++i)
      cout << "\t" << courses_names[i] << " = " << grades[i] << "\n";
  }
  bool GetCourseGradeInfo(int pos, pair<string, double> &result) const {
    if (pos < 0 || pos >= (int)grades.size()) {
      result = make_pair("", -1);
      return false;
    }
    result = make_pair(courses_names[pos], grades[pos]);
    return true;
  }
  string GetStudentId() const { return student_id; }
  int GetTotalCoursesCount() const { return grades.size(); }

  // Use GetTotalCoursesCount for naming consistency
  pair<double, double> get_total_gradesSum() const {
    double sum = 0, total = 0;
    for (int i = 0; i < (int)grades.size(); ++i)
      sum += grades[i], total += MAX_GRADE_PER_COURSE;
    return make_pair(sum, total);
  }
};

class StudentGradesInfoPrinter {
private:
  int iterator;
  StudentGradesInfo &StudInfo;

public:
  StudentGradesInfoPrinter(StudentGradesInfo &StudInfo)
      : StudInfo(StudInfo), iterator(0) {}

  bool HasNext() const {
    if (StudInfo.GetTotalCoursesCount() > iterator)
      return true;
    return false;
  }

  pair<string, double> GetNext() {
    pair<string, double> result;
    StudInfo.GetCourseGradeInfo(iterator, result);
    ++iterator;
    return result;
  }

  void ResetIterator() { iterator = 0; }
};

int StudentGradesInfo::statistics_total_prints = 0;

int main() {
  // StudentGradesInfo st1("S000123");
  // st1.AddGrade(70, "Math");
  // st1.AddGrade(70, "programming 1");
  // st1.AddGrade(85, "programming 2");
  // // std::cout << st1.GetTotalCoursesCount() << std::endl;
  //
  // st1.PrintAllCourses();
  //
  // pair<double, double> p = st1.get_total_gradesSum();
  // cout << p.first << "/" << p.second << "\n";
  //
  // cout << "Bye\n";

  StudentGradesInfo st1("S000123");
  StudentGradesInfoPrinter Printer(st1);

  st1.AddGrade(50, "Math");
  st1.AddGrade(60, "Programming 1");

  int limit = 3;
  std::cout << "Printing top " << limit << " Grades if available\n";
  while (limit-- && Printer.HasNext()) {
    pair<string, double> result = Printer.GetNext();
    std::cout << "\t" << result.first << " = " << result.second << "\n";
  }

  st1.AddGrade(70, "Algorithms");
  st1.AddGrade(67, "Programming 2");

  Printer.ResetIterator();

  limit = 3;

  std::cout << "\n Print Top " << limit << " Grades, if available\n";
  while (limit-- && Printer.HasNext()) {
    pair<string, double> result = Printer.GetNext();
    std::cout << "\t" << result.first << " = " << result.second << "\n";
  }
  return 0;
}
