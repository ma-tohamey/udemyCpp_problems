#include <cmath>
#include <iostream>

class Shape {

public:
  int width;
  int height;
  void setWidth(int width) { this->width = width; }
};

class Circle : public Shape {
public:
  int width;
  int height;
  void setWidth(int width) { this->width = width; }
};

int main(int argc, char *argv[]) {
  Circle c;
  c.setWidth(5);

  return 0;
}
