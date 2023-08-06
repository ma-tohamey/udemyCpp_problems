#include <iomanip>
#include <ios>
#include <iostream>
#include <tuple>

int main(int argc, char *argv[]) {
  int age;
  std::cout << "Enter your age: ";
  std::cin >> age;

  std::string full_name;
  std::cout << "Enter full name: ";
  std::cin.ignore('\n');
  getline(std::cin, full_name);

  std::cout << "Your age: " << age << " Your name: " << full_name << std::endl;

  std::cout << std::setprecision(20);
  std::cout << 0.1 + 0.2 << std::endl;
  float a = 0.1 + 0.2;
  std::cout << std::boolalpha;
  std::cout << (a == 0.3) << std::endl;

  return 0;
}
