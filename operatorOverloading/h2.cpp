#include <iostream>

std::string operator*(const std::string &str, const int multi) {
  if (multi <= 0)
    return "";

  std::string result;
  for (int i = 0; i < multi; ++i)
    result += str;
  return result;
}

int main(int argc, char *argv[]) {
  std::string a = "bad";
  std::string b = "I am " + a * 3 + ", right?";
  std::cout << b << std::endl;
  return 0;
}
