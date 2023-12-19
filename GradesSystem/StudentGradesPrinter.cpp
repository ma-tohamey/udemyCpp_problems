#include "StudentGradesPrinter.h"

StudentGradesInfoPrinter::StudentGradesInfoPrinter(const StudentGradesInfo &StudInfo)
    : StudInfo(StudInfo), iterator(0) {}

bool StudentGradesInfoPrinter::HasNext() const {
  if (StudInfo.GetTotalCoursesCount() > iterator)
    return true;
  return false;
}

std::pair<std::string, double> StudentGradesInfoPrinter::GetNext() {
  std::pair<std::string, double> result;
  StudInfo.GetCourseGradeInfo(iterator, result);
  ++iterator;
  return result;
}

void StudentGradesInfoPrinter::ResetIterator() { iterator = 0; }
