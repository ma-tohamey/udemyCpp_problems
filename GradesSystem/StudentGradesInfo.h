#pragma onece
#include <iostream>
#include <vector>

class StudentGradesInfo {
private:
  std::string student_id;
  std::vector<double> grades;
  std::vector<std::string> courses_names;
  static int statistics_total_prints;
  const int MAX_GRADE_PER_COURSE = 100.00;

  double ValidateGrade(int grade);

public:
  StudentGradesInfo(std::string student_id);

  bool AddGrade(double grade, std::string course_name);
  void PrintAllCourses() const;
  bool GetCourseGradeInfo(int pos,
                          std::pair<std::string, double> &result) const;
  std::string GetStudentId() const;

  int GetTotalCoursesCount() const;

  // Use GetTotalCoursesCount for naming consistency
  std::pair<double, double> get_total_gradesSum() const;
};
