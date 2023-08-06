// rectangle class

#include <iostream>

class rect {
private:
  double width;
  double height;

public:
  rect() {
    width = 0;
    height = 0;
  }
  rect(double _height, double _width) {
    height = _height;
    width = _width;
  }

  // setters
  void set_height(double height) { this->height = height; }
  void set_width(double width) { this->width = width; }

  // getters
  double get_height() { return height; }
  double get_width() { return width; }
  double get_area() { return width * height; }
  double get_premiter() { return 2 * (width + height); }
};

int main(int argc, char *argv[]) {
  rect st_rect;
  st_rect.set_height(10);
  st_rect.set_width(5);
  std::cout << st_rect.get_area() << std::endl;
  std::cout << st_rect.get_premiter() << std::endl;
  return 0;
}
