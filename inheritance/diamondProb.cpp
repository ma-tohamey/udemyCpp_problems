#include <iostream>

class LivingThing {
public:
  // LivingThing(int x) { std::cout << "Parameriezed LivingThing constructor"; }
  LivingThing() { std::cout << "Not Parameriezed LivingThing constructor\n"; }
};

class Animal : virtual public LivingThing {
public:
  Animal() { std::cout << "Animal constructor\n"; }
  void breathe() {}
};

class Reptile : virtual public LivingThing {
public:
  Reptile() { std::cout << "Reptile constructor\n"; }
  // void breathe();
};

class Snake : public Reptile, public Animal {};

int main(int argc, char *argv[]) {
  Snake s1;
  s1.breathe();

  return 0;
}
