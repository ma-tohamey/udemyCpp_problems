#include <iostream>
#include <map>
#include <ostream>

class Double {
private:
  double Duble;
  int IntDouble;

public:
  Double(double Duble) : Duble(Duble), IntDouble(Duble * 1000) {}

  bool operator>=(const Double &other) const {
    return IntDouble >= other.IntDouble;
  }
  bool operator<=(const Double &other) const {
    return IntDouble <= other.IntDouble;
  }
  bool operator>(const Double &other) const {
    return IntDouble > other.IntDouble;
  }
  bool operator<(const Double &other) const {
    return IntDouble < other.IntDouble;
  }
  bool operator==(const Double &other) const {
    return IntDouble == other.IntDouble;
  }
};

int main(int argc, char *argv[]) {
  double d1 = 1 + 3.0 / 7.0 - 1;
  double d2 = 3.0 / 7.0;

  std::cout << d1 << " " << d2 << " " << (d1 == d2) << std::endl;

  Double cd1(d1);
  Double cd2(d2);

  std::cout << (cd1 == cd2) << std::endl;

  std::map<double, std::string> firstmp;
  firstmp[d1] = 10;
  firstmp[d2] = 20;
  for (auto &ele : firstmp)
    std::cout << ">>> " << firstmp.size() << " " << ele.first << " "
              << ele.second << std::endl;

  std::map<Double, std::string> secondmp; // so just to make any class as key in
                                          // a map it must be comparable
  secondmp[cd1] = 10;
  secondmp[cd2] = 20;

  std::cout << secondmp.size() << std::endl;

  // for (auto &ele : secondmp)
  //   std::cout << ">>> " << ele.first << " " << ele.second << std::endl;

  return 0;
}
