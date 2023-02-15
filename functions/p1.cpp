#include <iostream>
using namespace std;

int max(int a, int b) {
  int max = a;
  if (b > a) {
    max = b;
  }
  return max;
}
int max(int a, int b, int c) { return max(a, max(b, c)); };
int max(int a, int b, int c, int d) { return max(a, max(b, c, d)); };
int max(int a, int b, int c, int d, int e) { return max(a, max(b, c, d, e)); };
int max(int a, int b, int c, int d, int e, int f) {
  return max(a, max(b, c, d, e, f));
};

int main(int argc, char *argv[]) {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << max(a, b, c, d, e, f) << endl;
  return 0;
}
