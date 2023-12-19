#include <iostream>

class Person {
private:
  std::string name;
  std::string gender;
  float age;

public:
  Person() : name("unknown"), gender("unknown"), age(0) {}

  Person(std::string n, std::string g, float a) : name(n), gender(g), age(a) {}

  void set_age(float a) { age = a; }
  const float get_age() { return age; }

  void set_name(std::string n) { name = n; }
  const std::string &get_name() { return name; }

  void set_gender(std::string g) { gender = g; }
  const std::string &get_gender() { return gender; }

  void display() {
    std::cout << "The Basic data" << std::endl;
    std::cout << name << " " << gender << " " << age << std::endl;
  }
};

class student : public Person {
private:
  int level;
  float GPA;
  std::string depart;

public:
  student(std::string n, std::string g, float a, int level, float GPA,
          std::string depart)
      : Person(n, g, a), level(level), GPA(GPA), depart(depart) {}
  void set_level(int level) { this->level = level; }
  int get_level() const { return level; }

  void set_GPA(float GPA) { this->GPA = GPA; }
  float get_GPA() const { return GPA; }

  void set_depart(const std::string &depart) { this->depart = depart; }
  const std::string &get_depart() const { return depart; }
};
int main(int argc, char *argv[]) {
  student s1;
  s1.display();
  s1.set_age(30);
  s1.set_name("mahamed");
  s1.set_gender("male");
  s1.set_depart("IS");
  s1.set_GPA(3.5);
  s1.display();
  return 0;
}
