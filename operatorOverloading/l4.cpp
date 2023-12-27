#include <iostream>
#include <istream>
#include <ostream>

class MyPair {
private:
  int first, second;

public:
  MyPair() {}
  MyPair(int first, int second) : first(first), second(second) {}

  MyPair operator+(const MyPair &other) {
    return MyPair(first + other.first, second + other.second);
  }

  void operator++() {
    first++;
    second++;
  }

  // to make postfix just add int between ()
  void operator++(int) {
    first++;
    second++;
  }

  void operator!() {
    first *= -1;
    second *= -1;
  }

  int operator[](int pos) const {
    if (pos == 0)
      return first;
    return second;
  }

  int &operator[](int pos) {
    if (pos == 0)
      return first;
    return second;
  }

  void print() { std::cout << "(" << first << "," << second << ")\n"; }
  int GetFirst() const { return first; }
  void SetFirst(int first) { this->first = first; }
  int GetSecond() const { return second; }
  void SetSecond(int second) { this->second = second; }

  // std::istream &operator>>(std::istream &input) {
  //   input >> first;
  //   input >> second;
  //   return input;
  // }
  // friend std::istream &operator>>(std::istream &input, MyPair &pair);
};

// std::istream &operator>>(std::istream &input, MyPair &pair) {
std::istream &operator>>(MyPair &pair, std::istream &input) {
  int a, b;
  input >> a >> b;
  pair.SetFirst(a);
  pair.SetSecond(b);
  // input >> pair.first >> pair.second;
  return input;
}

std::ostream &operator<<(std::ostream &output, const MyPair &pair) {
  output << pair.GetFirst() << " " << pair.GetSecond();
  return output;
}

int main(int argc, char *argv[]) {
  MyPair x;

  x >> std::cin;
  // std::cin >> x;

  std::cout << x << std::endl;

  return 0;
}
