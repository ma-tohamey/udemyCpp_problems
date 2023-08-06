#include <iostream>

class ClassA {
private:
  int *val;

public:
  ClassA(int v) {
    val = new int;
    *val = v;
  }

  ~ClassA() {
    delete val;
    val = nullptr;
  }

  const int *GetVal() { return val; }

  void SetVal(int *val) { this->val = val; }
};

int main(int argc, char *argv[]) {
  ClassA a1(10);
  ClassA a2(20);

  // a2.SetVal(a1.GetVal());

  std::cout << a1.GetVal() << ' ' << a2.GetVal() << std::endl;

  return 0;
}
