#include <iostream>
#include <queue>
using namespace std;

struct our_stack {
  queue<int> q;

  void push(int val) {
    q.push(val);

    // for (int i = 1; i < q.size(); i++) {
    //   int front_num = q.front();
    //   q.pop();
    //   q.push(front_num);
    // }

    for (int i = 0; i < q.size(); i++) {
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
  s.push(4);
  s.push(5);

  while (!s.empty())
    cout << s.top() << " ", s.pop();
  cout << endl;

  return 0;
}
