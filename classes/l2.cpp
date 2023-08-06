#include <iostream>

class rect {
private:
  double width;
  double height;

public:
  rect() : rect(0.0, 0.0){};
  rect(double width, double height) : width(0.0), height(0.0){};
  ~rect() { std::cout << "Destructed" << std::endl; }
};

int main(int argc, char *argv[]) {
  rect r1;
  return 0;
}
