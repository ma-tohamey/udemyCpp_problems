#include <iostream>

class Quote {
private:
  int internal;

  std::string GetQuote() {
    return "The way to get started is to "
           "quit talking and begin doing";
  }

public:
  int external;

  Quote() { internal = 3, external = 7; }

  void print() { std::cout << GetQuote() << std::endl; }
};

int main(int argc, char *argv[]) {
  // some operations

  Quote q;
  std::cout << q.external << std::endl;
  q.print();
  return 0;
}
