#include <iostream>
using namespace std;

template <class T> void fun(T a) { cout << "[" << a << "]"; }

template <> int fun(string str) {
  cout << "{{" << str << "}}";

  return str.size();
}
int main(int argc, char *argv[]) {

  fun(10.5), fun("mostafa");

  return 0;
}
