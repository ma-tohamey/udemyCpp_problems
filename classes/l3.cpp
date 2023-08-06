#include <iostream>
using namespace std;

class myVector {
private:
  int *arr;
  int len = 100;

public:
  myVector(int _len, int default_value = 0) {
    len = _len;
    arr = new int[len];

    for (int i = 0; i < len; ++i)
      arr[i] = default_value;
  }

  int get(int pos) { return arr[pos]; }

  ~myVector() { delete[] arr; }
};

int main(int argc, char *argv[]) {
  myVector v(10, 12345);

  cout << v.get(5);

  return 0;
}
