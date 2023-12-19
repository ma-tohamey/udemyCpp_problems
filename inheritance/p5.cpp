#include <iostream>

class Robot {
public:
  void drive();
  void clean();
  void do_funny_movies();
};

class Animal {
public:
  void go_toeilt();
  void make_sound();
};

class Cat : public Animal {
public:
  void make_sound();
};

class Dog : public Animal {
public:
  void make_sound();
};

int main(int argc, char *argv[]) {
  // some code
  return 0;
}
