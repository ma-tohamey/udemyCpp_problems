#include <iostream>

class tri {
private:
  float a;
  float circumference;
  float area;

public:
  void setA(float length) {
    a = length;
    circumference = a * 3;
    area = (1.73 * a * a) / 4;
  }

  void printResults(const tri &);
  friend void printResults(const tri &);
  friend class Homework;
};

class Homework {
public:
  void printResults(const tri &et) {
    std::cout << "circumference = " << et.circumference << std::endl;
    std::cout << "area = " << et.area << std::endl;
    std::cout << et.a << std::endl;
  }

  friend class et;
};

int main(int argc, char *argv[]) {
  // code

  tri et;
  et.setA(3);

  Homework hw;
  hw.printResults(et);
  et.printResults(et);

  return 0;
}
