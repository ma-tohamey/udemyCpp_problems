#include <iostream>
#include <string>

class Entity {
private:
  const std::string m_name;
  int quantity;

public:
  Entity() : m_name("unknown"), quantity(0) {}

  Entity(const std::string &m_name, int &quantity)
      : m_name(m_name), quantity(quantity) {}

  void print() { std::cout << m_name << ' ' << quantity << std::endl; }
};

int main(int argc, char *argv[]) {
  Entity e;
  e.print();
  return 0;
}
