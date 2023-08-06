#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string name;
  std::cout << "Give me your name and surname: " << std::endl;
  std::cin >> name;
  int age;
  std::cout << "Give me your age: " << std::endl;
  std::cin >> age;

  std::cout << std::cin.rdstate() << std::endl;
  std::cin.clear();
  std::cout << std::cin.rdstate() << std::endl;

  std::cout << std::setprecision(32);
  float a = 3.333333333333333333333333333333333333333333;
  double b = 3.33333333333333333333333333333333333333333;

  std::cout << a << std::endl;
  std::cout << b << std::endl;

  float i = 6666.333333333333333333;
  double k = 823.33333333333333333;

  std::cout << std::setprecision(17);
  std::cout << i << std::endl;
  std::cout << k << std::endl;

  return 0;
}
