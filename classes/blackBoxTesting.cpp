// buggy old code
#include <assert.h>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class StudentGradesInfo {
private:
  string student_id;
  vector<double> grades;
  vector<string> courses_names;
  const int MAX_GRADE_PER_COURSE = 100.0;

  static int statistics_total_prints;

  double AdjustGrade(double grade) const {
    if (grade < 0)
      return 0;
    if (grade > MAX_GRADE_PER_COURSE)
      return MAX_GRADE_PER_COURSE;
    return grade;
  }

  friend class StudentGradesInfoWhitekBoxTester;

public:
  StudentGradesInfo(string student_id) : student_id(student_id) {}

  bool AddGrade(double grade, const string &course_name) {
    grade = AdjustGrade(grade);

    for (int i = 0; i < (int)courses_names.size(); ++i)
      if (course_name == courses_names[i])
        return false; // already added

    grades.push_back(grade);
    courses_names.push_back(course_name);

    return true;
  }

  void PrintAllCourses() const {
    ++statistics_total_prints;

    cout << "Grades for student: " << GetStudentId() << "\n";
    for (int course_idx = 0; course_idx < (int)courses_names.size();
         ++course_idx)
      cout << "\t" << courses_names[course_idx] << " = " << grades[course_idx]
           << "\n";
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

  pair<double, double> GetTotalGradesSum() const {
    double sum = 0, total = 0;
    for (int grade_idx = 0; grade_idx < (int)grades.size(); ++grade_idx)
      sum += grades[grade_idx], total += MAX_GRADE_PER_COURSE;
    return make_pair(sum, total);
  }
};

class StudentGradesInfoPrinter {
private:
  const StudentGradesInfo &st;
  int iterator = 0;

public:
  StudentGradesInfoPrinter(const StudentGradesInfo &st) : st(st) {}

  void ResetIterator() { iterator = 0; }
  bool HasNext() { return iterator < st.GetTotalCoursesCount(); }

  pair<string, double> GetNext() {
    pair<string, double> result;
    st.GetCourseGradeInfo(iterator++, result);
    return result;
  }
};

class StudentGradesInfoWrapper {
private:
  static int TotalStudents;
  static int TotalPrints;
  string student_id;
  // StudentGradesInfo *st;
  StudentGradesInfo st;

public:
  StudentGradesInfoWrapper(string student_id)
      : student_id(student_id), st(StudentGradesInfo(student_id)) {
    ++TotalStudents;
  }

  // ~StudentGradesInfoWrapper() { delete st; }

  bool AddGrade(double grade, const string &course_name) {
    return st.AddGrade(grade, course_name);
  }

  void PrintAllCourses() const {
    st.PrintAllCourses();
    ++TotalPrints;
  }

  bool GetCourseGradeInfo(int pos, pair<string, double> &result) const {
    return st.GetCourseGradeInfo(pos, result);
  }

  const string &GetStudentId() const { return student_id; }

  const int GetTotalCoursesCount() const { return st.GetTotalCoursesCount(); }

  pair<double, double> GetTotalGradesSum() const {
    return st.GetTotalGradesSum();
  }

  static int GetTotalStudents() { return TotalStudents; }
  // static int GetTotalPrints() { return TotalPrints; }
  static int GetTotalPrints() { return TotalPrints; }
};

int StudentGradesInfoWrapper::TotalPrints = 0;
int StudentGradesInfoWrapper::TotalStudents = 0;
int StudentGradesInfo::statistics_total_prints = 0;

class StudentGradesInfoWhitekBoxTester {
public:
  const int MAX_GRADE_PER_COURSE = 100;

  void Test_AdjustGrade() {
    StudentGradesInfo s1("#978173498719");
    assert(s1.AdjustGrade(91.3) == 91.3);
    assert(s1.AdjustGrade(18.5) == 18.5);
    assert(s1.AdjustGrade(35) == 35.0);
    assert(s1.AdjustGrade(-19) == 0);
    assert(s1.AdjustGrade(-19.5) == 0);
    assert(s1.AdjustGrade(105) == 100);
    assert(s1.AdjustGrade(300) == 100);
  }

  void Test_statisticsTotalPrints() {
    // remember you made previous student in the previous function
    StudentGradesInfo s1("#978173498719");
    s1.PrintAllCourses();
    assert(StudentGradesInfo::statistics_total_prints == 1);
    StudentGradesInfo s2("#978173498719");
    s2.PrintAllCourses();
    assert(StudentGradesInfo::statistics_total_prints == 2);
    StudentGradesInfo s3("#978173498");
    s3.PrintAllCourses();
    assert(StudentGradesInfo::statistics_total_prints == 3);

    s1.PrintAllCourses();
    assert(StudentGradesInfo::statistics_total_prints == 4);

    // no errors throwen
  }

  void TestAll() {
    Test_AdjustGrade();
    Test_statisticsTotalPrints();
  }
};

class StudentGradesInfoBlackBoxTester {
private:
  const int MAX_GRADE_PER_COURSE = 100;

public:
  void Test_AddGrade() {
    StudentGradesInfo s1("$10983749861");
    s1.AddGrade(-19, "math1"); // it will add math1 with grade 0;
    assert(s1.GetTotalCoursesCount() == 1);

    s1.AddGrade(120, "math2");
    assert(s1.GetTotalCoursesCount() == 2);

    s1.AddGrade(80, "prog1");
    assert(s1.GetTotalCoursesCount() == 3);
    s1.AddGrade(60, "prog1");
    assert(s1.GetTotalCoursesCount() == 3);
  }

  void Test_GetCourseGradeInfo() {
    StudentGradesInfo s1("$1983748698189");

    s1.AddGrade(80, "math1");
    s1.AddGrade(60, "math2");
    s1.AddGrade(90, "prog1");
    s1.AddGrade(100, "prog2");

    pair<string, double> result;

    // assert(s1.GetCourseGradeInfo(3, result) == true);
    // assert(s1.GetCourseGradeInfo(s1.GetTotalCoursesCount(), result) ==
    // false); assert(s1.GetCourseGradeInfo(-5, result) == false);

    //
    // s1.GetCourseGradeInfo(0, result);
    // assert(result.first == "Math");
    // assert(result.second == MAX_GRADE_PER_COURSE);
    //
    // s1.GetCourseGradeInfo(1, result);
    // assert(result.first == "programming 1");
    // assert(result.second == 70);
  }

  void Test_TotalGradesSum() {
    StudentGradesInfo s1("$9187984739198");
    pair<double, double> p;
    assert(p.first == 0);
    assert(p.second == 0);
    s1.AddGrade(70, "prog1");
    s1.AddGrade(80, "prog2");
    s1.AddGrade(90, "prog3");
    s1.AddGrade(100, "prog4");
    s1.AddGrade(200, "Math1");

    p = s1.GetTotalGradesSum();
    assert(p.first == 440);
    assert(p.second == 5 * MAX_GRADE_PER_COURSE);

    s1.AddGrade(-200, "Math2");
    p = s1.GetTotalGradesSum();
    assert(p.first == 440);
    assert(p.second == s1.GetTotalCoursesCount() * MAX_GRADE_PER_COURSE);

    // p = s1.GetTotalGradesSum();
    // assert(p.first == 340);
    // assert(p.second == 400);
  }

  void TestAll() {
    Test_AddGrade();
    Test_GetCourseGradeInfo();
    Test_TotalGradesSum();
  }
};

int main() {

  // StudentGradesInfoBlackBoxTester().TestAll();
  // StudentGradesInfoWhitekBoxTester().TestAll();

  // StudentGradesInfo st1("#19374ouoieuroiweu");
  // StudentGradesInfoPrinter printer(st1);
  //
  // st1.AddGrade(50, "math1");
  // st1.AddGrade(60, "math2");
  //
  // int limit = 3;
  //
  // cout << "Printing top " << limit << " Grades, if available\n";
  // while (limit-- && printer.HasNext()) {
  //   pair<string, double> result = printer.GetNext();
  //   cout << '\t' << result.first << " = " << result.second << '\n';
  // }
  //
  // st1.AddGrade(70, "Algorithms");
  // st1.AddGrade(67, "programming 2");
  //
  // printer.ResetIterator();
  // limit = 3;
  // // limit = 4;
  // cout << "\nPrinting top " << limit << " Grades, if available\n";
  // while (limit-- && printer.HasNext()) {
  //   pair<string, double> result = printer.GetNext();
  //
  //   cout << "\t" << result.first << " = " << result.second << "\n";
  // }

  StudentGradesInfoWrapper st1("#o9817398471");
  st1.AddGrade(70, "Math");
  st1.AddGrade(70, "Programing 1");
  st1.AddGrade(85, "Programing 2");

  st1.PrintAllCourses();

  pair<double, double> p = st1.GetTotalGradesSum();
  cout << p.first << '/' << p.second << endl;

  StudentGradesInfoWrapper st2("#98173948739871984379");
  st2.PrintAllCourses();
  st2.PrintAllCourses();
  st2.PrintAllCourses();

  cout << "Total Students " << StudentGradesInfoWrapper::GetTotalStudents()
       << endl;
  cout << "Total Prints " << StudentGradesInfoWrapper::GetTotalPrints() << endl;

  cout << "Bye" << endl;

  return 0;
}
