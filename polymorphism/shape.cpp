#include <iostream>

class Shape {
private:
  std::string name;

public:
  Shape(std::string name) : name(name) {}

  virtual double Area() const {
    throw std::logic_error("Not impelemented, Do override");
    return -1;
  }

  std::string GetShapeName() const { return name; }

  void SetShapeName(std::string name) { this->name = name; }
  virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
  double width;
  double height;

public:
  Rectangle(std::string name, double width, double height)
      : Shape(name), width(width), height(height) {}

  double Area() const override { return width * height; }
};

class Circle : public Shape {
private:
  const double PI = 3.14;
  double radius;

public:
  Circle(std::string name, double radius) : Shape(name), radius(radius) {}
  double Area() const override { return PI * (radius * radius); }
};
void PrintArea(const Shape *shape) {
  std::cout << "this shape is: " << shape->GetShapeName() << std::endl;
  std::cout << "it's Area is: " << shape->Area() << std::endl;
}

int main(int argc, char *argv[]) {

  Rectangle rect("reci1", 10, 6);
  PrintArea(&rect);

  Circle circle("circle1", 7.3);
  PrintArea(&circle);

  return 0;
}
