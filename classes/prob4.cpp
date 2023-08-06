#include <iostream>
#include <stdexcept>

class MyVector {
private:
  int *arr;
  int len = 100;

public:
  MyVector(int len, int default_value = 0) {
    this->len = len;
    this->arr = new int[len];

    for (int i = 0; i < len; ++i)
      this->arr[i] = default_value;
  }

  MyVector(const MyVector &other) : len(other.len) {
    arr = new int[len];
    for (int i = 0; i < len; ++i)
      arr[i] = other.arr[i];
  }

  int &operator[](unsigned int index) {
    if (index >= len)
      throw std::out_of_range("ERROR: out_of_boundries");
    return arr[index];
  }

  const int get(int pos) {
    if (pos >= len)
      throw std::out_of_range("ERROR: out_of_boundries");
    return this->arr[pos];
  }

  void set(int value) {
    for (int i = 0; i < len; ++i)
      arr[i] = value;
  }

  int &get_len() { return len; }
  ~MyVector() { delete[] this->arr; }
};

int main(int argc, char *argv[]) {
  MyVector v1(10, 12345);
  MyVector v2(v1);

  std::cout << v1.get_len() << ' ' << v2.get_len() << std::endl;

  v2.set(6789);
  v2[2] = 3456;
  v2.get_len() = 99;

  // std::cout << v2[10] << std::endl;
  // std::cout << v2.get(10) << std::endl;
  // v2[1] = 6789;
  //
  // for (int i = 0; i < 10; ++i)
  //   std::cout << v1[i] << ' ' << v2[i] << std::endl;

  std::cout << v1.get_len() << ' ' << v2.get_len() << std::endl;
  return 0;
}
