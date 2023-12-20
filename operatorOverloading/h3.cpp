#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

class MyPair {
private:
  int first, second;

public:
  MyPair(int first, int second) : first(first), second(second) {}

  bool operator<(const MyPair &other) {
    // return std::tie(first, second) < std::tie(other.first, other.second);
    if (first == other.first)
      return (second < other.second);
    return (first < other.first);
  }
  virtual void print() {
    std::cout << "(" << GetFirst() << "," << GetSecond() << ")\n";
  }
  int GetFirst() const { return first; }
  void SetFirst(int first) { this->first = first; }
  int GetSecond() const { return second; }
  void SetSecond(int second) { this->second = second; }
  virtual ~MyPair() {}
};

class NamedPair : public MyPair {
private:
  std::string str;

public:
  NamedPair(std::string str, int first, int second)
      : MyPair(first, second), str(str) {}

  bool operator<(const NamedPair &other) {
    if (str == other.str)
      return MyPair::operator<(other);
    // return std::tie(str) < std::tie(other.str);
    return str < other.str;
  }

  virtual void print() override {
    std::cout << "(" << str << ": " << GetFirst() << ", " << GetSecond() << ")"
              << std::endl;
  }
};

int main(int argc, char *argv[]) {
  // std::vector<MyPair> vec;
  //
  // vec.push_back(MyPair(10, 20));
  // vec.push_back(MyPair(10, 7));
  // vec.push_back(MyPair(1, 200));

  std::vector<NamedPair> vec;
  vec.push_back(NamedPair("A", 10, 20));
  vec.push_back(NamedPair("B", 10, 7));
  vec.push_back(NamedPair("B", 1, 200));

  sort(vec.begin(), vec.end());

  for (auto &pair : vec)
    pair.print();
  return 0;
}
