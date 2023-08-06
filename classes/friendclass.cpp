#include <iostream>

class person {
private:
  std::string name;
  std::string gender;
  double age;

public:
  person();
  person(std::string n, std::string g, float a) : name(n), gender(g), age(a){};

  void set_name(std::string n) { name = n; }

  std::string get_name() { return name; }

  friend void print(const person &p);
};

void print(const person &p) {
  std::cout << "the basic data of person" << std::endl;
  std::cout << "name = " << p.name << " age = " << p.age
            << " gender = " << p.gender << std::endl;
}
int main(int argc, char *argv[]) {
  // code

  person x("Ahmed", "male", 23);
  print(x);
  return 0;
}
