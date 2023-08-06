#include <iostream>

class Vec2 {
public:
  Vec2(int only_first) { std::cout << "first constructor works" << std::endl; }
  Vec2(int first_val, int sec_val) {
    std::cout << "second constructor works" << std::endl;
  }
};

int main(int argc, char *argv[]) {
  // some operations
  Vec2(1, 2);
  // Vec2(2, 5);
  return 0;
}
