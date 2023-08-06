#include <cstring>
#include <iostream>

class String {
private:
  int len;
  char *str;

public:
  String(const char *string) {
    len = strlen(string);
    str = new char[len];
    memcpy(str, string, len + 1);
    str[len] = 0;
  }
  String(String &other) : len(other.len) {
    str = new char[len];
    memcpy(str, other.str, len + 1);
    str[len] = 0;
  }

  ~String() { delete[] str; }

  void print() { std::cout << str << std::endl; }

  char &operator[](int index) { return str[index]; }
};

int main(int argc, char *argv[]) {
  String st1("hello, world");
  String st2(st1);
  st2[5] = '-';
  st1.print();
  st2.print();

  return 0;
}
