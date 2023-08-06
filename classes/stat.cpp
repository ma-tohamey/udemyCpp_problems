#include <iostream>

struct Entity {
  static int x, y;
  int z;

  static void print() { std::cout << x << ", " << y << ' ' << z << std::endl; }
};

int Entity::x;
int Entity::y;

int main(int argc, char *argv[]) {
  // code

  Entity e;
  Entity::x = 2;
  Entity::y = 3;

  Entity e1;
  Entity::x = 5;
  Entity::y = 8;

  e.print();

  Entity::print();
  Entity::print();
  return 0;
}
