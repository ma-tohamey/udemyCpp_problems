#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct our_stack {
  queue<int> q;

  void push(int val) {
    // some operations
    int s = q.size();
    q.push(val);

    for (int i = 0; i < s; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  void pop() {
    if (!q.empty())
      q.pop();
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

int main(int argc, char *argv[]) {
  our_stack s;
  s.push(1);
  s.push(2);
  s.push(3);

  while (!s.empty())
    cout << s.top() << ' ', s.pop();
  cout << endl;
  return 0;
}
