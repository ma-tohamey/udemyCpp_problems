#include <iostream>
#include <vector>

std::vector<int> operator+(std::vector<int> &otherOne,
                           std::vector<int> &otherTwo) {

  if ((int)otherOne.size() > (int)otherTwo.size()) {
    for (int i = 0; i < (int)otherTwo.size(); ++i)
      otherOne[i] += otherTwo[i];
    return otherOne;
  }
  for (int i = 0; i < (int)otherOne.size(); ++i)
    otherTwo[i] += otherOne[i];
  return otherTwo;
}

int main(int argc, char *argv[]) {
  std::vector<int> b = {1, 2, 3, 4};
  std::vector<int> a = {10, 20};

  std::vector<int> c = a + b;

  for (int i = 0; i < (int)c.size(); ++i)
    std::cout << c[i] << " ";
  std::cout << std::endl;
  return 0;
}
