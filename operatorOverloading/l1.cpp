#include <iostream>
class MyPair {
private:
  int first, second;

public:
  MyPair(int first, int second) : first(first), second(second) {}

  // MyPair Add(const MyPair &other) {
  //   MyPair result(first + other.first, second + other.second);
  //   return result;
  // }

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

  void print() { std::cout << "(" << first << "," << second << ")\n"; }
  int GetFirst() const { return first; }
  void SetFirst(int first) { this->first = first; }
  int GetSecond() const { return second; }
  void SetSecond(int second) { this->second = second; }
};

int main(int argc, char *argv[]) {
  MyPair x(1, 2);
  MyPair y(10, 20);

  // MyPair z = x.Add(y);
  MyPair z = x + y;
  z.print();
  !z;
  z.print();
  // MyPair mine = z.operator+(x);
  // mine.operator++();
  // mine.print();
  // ++z;
  // z++;
  // z.print();

  return 0;
}
