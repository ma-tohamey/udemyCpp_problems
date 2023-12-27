#include <iostream>

class MyNumber {
public:
  int num;
  MyNumber(int num) : num(num) {}
};

MyNumber operator^(const MyNumber &c1, int pow) {
  int res = 1;
  while (pow--)
    res *= c1.num;
  return MyNumber(res);
}

MyNumber operator+(const MyNumber &c1, const MyNumber &c2) {
  return MyNumber(c1.num + c2.num);
}

int main(int argc, char *argv[]) {
  MyNumber x(2);
  MyNumber res1 = x ^ 3;
  MyNumber res2 = 1 + x ^ 3;
  std::cout << res1.num << " " << res2.num << std::endl;
  return 0;
}
