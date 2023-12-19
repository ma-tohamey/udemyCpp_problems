#include "StudentGradesInfo.h"
#include <iostream>
#include <vector>

StudentGradesInfo::StudentGradesInfo(std::string student_id)
    : student_id(student_id) {}

double StudentGradesInfo::ValidateGrade(int grade) {
  if (grade < 0)
    return 0;
  if (grade > MAX_GRADE_PER_COURSE)
    return MAX_GRADE_PER_COURSE;
  return grade;
}

bool StudentGradesInfo::AddGrade(double grade, std::string course_name) {
  grade = ValidateGrade(grade);

  for (int i = 0; i < (int)courses_names.size(); ++i)
    if (course_name == courses_names[i])
      return false; // already added
  courses_names.push_back(course_name);
  grades.push_back(grade);
  return true;
}

void StudentGradesInfo::PrintAllCourses() const {
  ++statistics_total_prints;

  std::cout << "Grades for student: " << GetStudentId() << "\n";
  for (int i = 0; i < (int)grades.size(); ++i)
    std::cout << "\t" << courses_names[i] << " = " << grades[i] << "\n";
}
bool StudentGradesInfo::GetCourseGradeInfo(
    int pos, std::pair<std::string, double> &result) const {
  if (pos < 0 || pos >= (int)grades.size()) {
    result = std::make_pair("", -1);
    return false;
  }
  result = make_pair(courses_names[pos], grades[pos]);
  return true;
}
std::string StudentGradesInfo::GetStudentId() const { return student_id; }
int StudentGradesInfo::GetTotalCoursesCount() const { return grades.size(); }

// Use GetTotalCoursesCount for naming consistency
std::pair<double, double> StudentGradesInfo::get_total_gradesSum() const {
  double sum = 0, total = 0;
  for (int i = 0; i < (int)grades.size(); ++i)
    sum += grades[i], total += MAX_GRADE_PER_COURSE;
  return std::make_pair(sum, total);
}

int StudentGradesInfo::statistics_total_prints = 0;
