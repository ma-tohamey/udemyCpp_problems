#include "StudentGradesPrinter.h"
#include <iostream>

int main(int argc, char *argv[]) {
  // StudentGradesInfo st1("S000123");
  //
  // st1.AddGrade(70, "Math");
  // st1.AddGrade(70, "Programming 1");
  // st1.AddGrade(85, "Programming 2");
  // st1.PrintAllCourses();
  // std::pair<double, double> p = st1.get_total_gradesSum();
  //
  // std::cout << p.first << '/' << p.second << std::endl;

  StudentGradesInfo st1("S000123");
  StudentGradesInfoPrinter Printer(st1);

  st1.AddGrade(50, "Math");
  st1.AddGrade(60, "Programming 1");

  int limit = 3;
  std::cout << "Printing top " << limit << " Grades if available\n";
  while (limit-- && Printer.HasNext()) {
    std::pair<std::string, double> result = Printer.GetNext();
    std::cout << "\t" << result.first << " = " << result.second << "\n";
  }

  st1.AddGrade(70, "Algorithms");
  st1.AddGrade(67, "Programming 2");

  Printer.ResetIterator();

  limit = 3;

  std::cout << "\n Print Top " << limit << " Grades, if available\n";
  while (limit-- && Printer.HasNext()) {
    std::pair<std::string, double> result = Printer.GetNext();
    std::cout << "\t" << result.first << " = " << result.second << "\n";
  }
  return 0;
}
