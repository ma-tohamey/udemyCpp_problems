#include <iostream>

class Shape {
public:
  virtual void draw() const { std::cout << "Drawing a shape" << std::endl; }
};

class Circle : public Shape {
public:
  void draw() const override { std::cout << "Drawing a circle" << std::endl; }
};

class Square : public Shape {
public:
  void draw() const override { std::cout << "Drawing a square" << std::endl; }
};

int main(int argc, char *argv[]) {
  Shape shape;
  Circle circle;
  Square square;

  Shape &refShape = circle;
  refShape.draw();
  return 0;
}
