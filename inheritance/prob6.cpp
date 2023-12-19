#include <iostream>

class DecoratedString : public std::string {
public:
  DecoratedString() {
    std::cout << "additional" << std::string::c_str() << std::endl;
  }
  using std::string::string;

  void decorate() {
    std::string::insert(0, "<<[[");
    std::string::insert(std::string::length(), "]]>>");
  }
};

int main(int argc, char *argv[]) {
  DecoratedString str = "I am learning CS";
  str.decorate();
  std::cout << str << std::endl;
  std::cout << (str == "<<[[I am learning CS]]>>") << std::endl;
  return 0;
}
