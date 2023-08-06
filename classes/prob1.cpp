#include <iostream>

class a {
public:
  a() { std::cout << "class a constructed" << std::endl; }
  ~a() { std::cout << "class a destructed" << std::endl; }
};

class b {
public:
  b() { std::cout << "class b constructed" << std::endl; }
  ~b() { std::cout << "class b destructed" << std::endl; }
};

class c {
public:
  c() { std::cout << "class c constructed" << std::endl; }
  ~c() { std::cout << "class c destructed" << std::endl; }
};

class entity {
public:
  a A;
  b B;
  c C;

  entity() : B(), A(), C() {}
};

int main(int argc, char *argv[]) {
  entity e;
  return 0;
}
