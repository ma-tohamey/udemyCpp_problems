#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class Array {
private:
  int size;
  int *ptr;

public:
  Array() : size(0), ptr(nullptr){};
  Array(int size) : size(size), ptr(new int[size]) {}
  Array(const Array &another) : size(another.size), ptr(new int[size]) {
    for (int i = 0; i < size; ++i)
      ptr[i] = another.ptr[i];
  }

  int getSize() { return size; }

  int &operator[](int pos) { return ptr[pos]; }
  int &operator[](int pos) const { return ptr[pos]; }

  void operator=(const Array &another) {
    size = another.size;
    ptr = new int[size];

    for (int i = 0; i < size; ++i)
      ptr[i] = another[i];
  }

  Array operator++() {
    Array cpy(size);
    for (int i = 0; i < size; ++i)
      cpy[i] = ++ptr[i];
    return cpy;
  }

  Array operator++(int) {
    Array cpy(size);
    for (int i = 0; i < size; ++i)
      cpy[i] = ptr[i]++;
    return cpy;
  }

  bool operator==(const Array &another) {
    if (size != another.size)
      return false;

    for (int i = 0; i < size; ++i)
      if (ptr[i] != another[i])
        return false;

    return true;
  }

  bool operator!=(const Array &another) { return !operator==(another); }

  ~Array() { delete[] ptr; }
};

class Array2D : public Array {
private:
  int rows;
  int cols;

public:
  Array2D(int rows = 2, int cols = 2)
      : Array(rows * cols), rows(rows), cols(cols) {}

  int &operator[](int i) { return Array::operator[](i); }
  int &operator()(int i, int j) const {
    int pos = i * cols + j;
    return Array::operator[](pos);
  }
  Array2D &operator++() {
    Array::operator++();
    return *this;
  }

  Array2D operator++(int) {
    Array2D cpy = *this;
    ++*this;
    return cpy;
  }
  friend ostream &operator<<(ostream &output, const Array2D &arr);
};

ostream &operator<<(ostream &output, const Array2D &arr) {
  for (int i = 0; i < arr.rows; ++i) {
    for (int j = 0; j < arr.cols; ++j) {
      output << arr(i, j) << " ";
    }
    output << "\n";
  }
  return output;
}

void test_Array2d() {
  Array2D arr1(2, 3);

  int counter = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      arr1(i, j) = counter++;
    }
  }

  cout << arr1 << "\n";

  Array2D arr2 = ++arr1; // copy
  cout << arr2 << "\n";

  if (arr2 == arr1)
    cout << "arr2 == arr1\n";
  else
    cout << "arr2 != arr1\n";

  Array2D arr3;
  arr3 = arr2++;
  cout << arr3 << "\n";

  if (arr3 != arr1)
    cout << "arr3 != arr1\n";
  else
    cout << "arr3 == arr1\n";
}

ostream &operator<<(ostream &out, Array &arr) {
  for (int i = 0; i < arr.getSize(); ++i)
    out << arr[i] << ' ';
  return out;
}

void test_Array() {
  Array arr1(6);

  int counter = 0;
  for (int i = 0; i < arr1.getSize(); ++i)
    arr1[i] = counter++;

  cout << arr1 << "\n";

  Array arr2 = ++arr1; // copy
  cout << arr2 << "\n";

  if (arr2 == arr1)
    cout << "arr2 == arr1\n";
  else
    cout << "arr2 != arr1\n";

  Array arr3;
  arr3 = arr2++;
  cout << arr3 << "\n";

  if (arr3 != arr1)
    cout << "arr3 != arr1\n";
  else
    cout << "arr3 == arr1\n";
}

int main() {
  test_Array();
  cout << "Bye\n";

  test_Array2d();
  cout << "Bye\n";
  return 0;
}
