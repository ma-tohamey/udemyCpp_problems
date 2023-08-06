#include <iostream>

class Rectangle {
private:
  double width;
  double height;

public:
  // Rectangle() { width = height = 0; }

  // Rectangle() : Rectangle(0.0, 0.0) {}

  Rectangle(double width, double height) : width(width), height(height) {}
};
int main(int argc, char *argv[]) {
  Rectangle r1(5, 10);

  return 0;
}
