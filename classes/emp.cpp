#include <iostream>
#include <string>

class emp {
private:
  int *salary{nullptr};
  char *name;

public:
  emp() = default;
  emp(int salary, std::string){};
};
int main(int argc, char *argv[]) {
  emp e1;
  // emp e1(10, "mostafa");
  return 0;
}
