#include <initializer_list>
#include <iostream>

class Adder {
private:
  int total_sum{};

public:
  Adder() {}
  Adder(const std::initializer_list<int> &lst) { Add(lst); }

  int Add(int a, int b) {
    total_sum += a + b;
    return total_sum;
  }

  int Add(const std::initializer_list<int> &lst) {
    int sum{};
    for (auto &value : lst)
      sum += value;
    total_sum += sum;
    return total_sum;
  }

  int GetCurrentSum() { return total_sum; }
};

int main(int argc, char *argv[]) {
  Adder adder{1, 2, 3};
  std::cout << adder.GetCurrentSum() << std::endl;

  adder.Add(3, 4);
  std::cout << adder.GetCurrentSum() << std::endl;

  adder.Add({3, 4});
  std::cout << adder.GetCurrentSum() << std::endl;

  adder.Add({3, 4, 3});
  std::cout << adder.GetCurrentSum() << std::endl;
  return 0;
}
