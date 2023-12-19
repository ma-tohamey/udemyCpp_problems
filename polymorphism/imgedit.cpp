#include <iostream>
#include <sstream>
#include <vector>

class Point {
private:
  double x;
  double y;

public:
  Point(double x, double y) : x(x), y(y) {}
  double GetX() const { return x; }

  void SetX(double x) { this->x = x; }

  double GetY() const { return y; }

  void SetY(double y) { this->y = y; }

  std::string ToString() const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ")";
    return oss.str();
  }
};

class Shape {
protected:
  int color;

public:
  Shape(int color) : color(color) {}
  virtual int ComputeArea() const {
    std::cout << "NOT Impelemented! --> (ComputeArea Function)\n";
    return -1;
  }

  virtual void Draw() const {
    std::cout << "NOT Impelemented! --> (Draw Function)\n";
  }

  int GetColor() const { return color; }
  void SetColor(int color) { this->color = color; }

  virtual Shape *Clone() const {
    std::cout << "NOT Impelemented --> (Clone Function)\n";
    return nullptr;
  }

  virtual Shape *Itself() const { return nullptr; }

  ~Shape() {}
};

class Rectangle : public Shape {
private:
  Point top_left;
  Point bottom_right;

public:
  Rectangle(int color, const Point &top_left, const Point &bottom_right)
      : Shape(color), top_left(top_left), bottom_right(bottom_right) {}

  virtual int ComputeArea() const override {
    return 10; // just compute
  }

  virtual void Draw() const override {
    // Shape::Draw();
    std::cout << "Drawing rectangle TL " << top_left.ToString() << " - BR "
              << bottom_right.ToString() << "\n";
  }

  virtual Shape *Clone() const override {
    return new Rectangle(*this); // here we are calling the copy constructor
  }

  virtual Shape *Itself() const override { return (Shape *)this; }

  // virtual Rectangle *Clone() {
  //   return new Rectangle(
  //       color, top_left,
  //       bottom_right); // here we are calling the normal constructor which is
  //                      // not recommended way
  // }
};

class Circle : public Shape {
private:
  double radius;
  Point center;

public:
  Circle(int color, Point center, double radius)
      : Shape(color), center(center), radius(radius) {}

  virtual int ComputeArea() const override {
    return 20; // just compute
  }
  virtual void Draw() const override {
    // Shape::Draw();
    std::cout << "Drawing circle center " << center.ToString() << " - radius "
              << radius << "\n";
  }

  virtual Shape *Itself() const override { return (Shape *)this; }
  virtual Shape *Clone() const override { return new Circle(*this); }
};

class ImageEditor {
protected:
  std::vector<Shape *> shapes;

public:
  // void AddShape(const Shape &shape) { shapes.push_back(shape.Clone()); }
  // void AddShape(Shape *shape) { shapes.push_back(shape); }
  void AddShape(const Shape &shape) { shapes.push_back(shape.Itself()); }
  //
  //

  // void AddCirlce() { shapes.push_back(new Circle(20, Point(8, 9), 3.5)); }
  //
  // void AddRectangle() {
  //   shapes.push_back(new Rectangle(10, Point(3, 4), Point(5, 6)));
  // }

  virtual void Draw() {
    std::cout << "ImageEditor::Draw\n";
    for (Shape *shapePtr : shapes)
      shapePtr->Draw();
  }

  virtual ~ImageEditor() {
    for (Shape *shape : shapes)
      delete shape;
    shapes.clear();
  }
};

class AdobeImageEditor : public ImageEditor {
public:
  void EnlargeShpaes(double percent) {
    for (auto shapePtr : shapes) {
      // Enlarge
    }
  }
};

void initalize(AdobeImageEditor *editor) {
  Rectangle *r1 = new Rectangle(10, Point(3, 4), Point(5, 6));
  Circle *c1 = new Circle(20, Point(8, 9), 3.5);

  editor->AddShape(*r1);
  editor->AddShape(*c1);
}

int main() {
  AdobeImageEditor *editor = new AdobeImageEditor();

  initalize(editor);

  editor->Draw();
  editor->EnlargeShpaes(0.5);

  delete editor;
  editor = nullptr;

  std::cout << "Bye";

  return 0;
}
