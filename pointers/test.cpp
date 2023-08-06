#include <iostream>
using namespace std;

class Entity {
private:
  int m_x, m_y;
  mutable int var;

public:
  int getX() const {
    var = 50;
    return m_x;
  }

  void setX(int x) { m_x = x; }
};

void print_entity(const Entity &e) { cout << e.getX() << endl; }

int main(int argc, char *argv[]) {
  Entity e;

  print_entity(e);

  return 0;
}
