#include <iostream>

class Rectangle {
private:
  double width;
  double height;

public:
  Rectangle(double width = 0.0, double height = 0.0)
      : width(width), height(height) {}

  double ComputeArea() const { return width * height; }

  double GetWidth() const { return width; }
  double Getheight() const { return height; }

  void SetWidth(int width) { this->width = width; }
  void SetHeight(int height) { this->height = height; }
};
int main(int argc, char *argv[]) {
  // code

  Rectangle r1(2, 3);
  std::cout << r1.ComputeArea() << std::endl;
  r1.SetWidth(10);
  std::cout << r1.ComputeArea() << std::endl;

  const Rectangle r2(4, 5);
  r2.ComputeArea();
  // r2.SetWidth(10);
  return 0;
}
