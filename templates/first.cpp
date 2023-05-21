#include <iostream>

using namespace std;

template <typename T> struct myqueue {
  T arr[100];
  int pos;

  myqueue() { pos = 0; }
  myqueue(T param_arr[], int len) {
    for (int i = 0; i < len; i++)
      arr[i] = param_arr[i];
    pos = len;
  }

  void add_front(T element) { arr[pos++] = element; }

  template <typename Type> void sum_and_add(Type a, Type b) {
    arr[pos++] = a + b;
  }

  void print() {
    for (int i = 0; i < pos; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
};

int main() {
  myqueue<string> q_str;
  q_str.add_front("mahmoud");
  q_str.add_front("altohamy");
  q_str.print();

  return 0;
}
