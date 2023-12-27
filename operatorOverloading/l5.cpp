#include <iostream>
#include <istream>
#include <ostream>

class MyPair {
private:
  int first, second;
  int *intptr = nullptr;

public:
  MyPair(int first) : MyPair(first, first) {}
  MyPair(int first, int second) : first(first), second(second) {}

  MyPair operator+(const MyPair &other) {
    return MyPair(first + other.first, second + other.second);
  }

  void print() { std::cout << "(" << first << "," << second << ")\n"; }
  int GetFirst() const { return first; }
  void SetFirst(int first) { this->first = first; }
  int GetSecond() const { return second; }
  void SetSecond(int second) { this->second = second; }
};

std::ostream &operator<<(std::ostream &output, const MyPair &pair) {
  output << pair.GetFirst() << " " << pair.GetSecond();
  return output;
}

MyPair operator+(int Intg, const MyPair &other) {
  return MyPair(Intg + other.GetFirst(), Intg + other.GetSecond());
}

int main(int argc, char *argv[]) {
  // MyPair x(5);
  // std::cout << x << std::endl;

  MyPair x(1, 2);
  MyPair y(3);
  MyPair w = 5;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << w << std::endl;

  MyPair z1 = x + 5.3;
  MyPair z2 = 3 + x;
  MyPair z3 = 3 + x + 5;

  std::cout << z1 << std::endl;
  std::cout << z2 << std::endl;
  std::cout << z3 << std::endl;

  return 0;
}
