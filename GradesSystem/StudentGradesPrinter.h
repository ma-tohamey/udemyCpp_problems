#include "StudentGradesInfo.h"
#include <iostream>

class StudentGradesInfoPrinter {
private:
  int iterator;
  StudentGradesInfo &StudInfo;

public:
  StudentGradesInfoPrinter(StudentGradesInfo &StudInfo);

  bool HasNext() const;

  std::pair<std::string, double> GetNext();

  void ResetIterator();
};
