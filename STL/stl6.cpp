#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print_que(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

void reverse_queue(queue<int> &q) {
  // reversing the queue by stack
  // stack<int> stk;
  // while (!q.empty()) {
  //   stk.push(q.front());
  //   q.pop();
  // }
  // while (!stk.empty()) {
  //   q.push(stk.top());
  //   stk.pop();
  // }
  /////////////////////////////////////
  // reversing the queue by recursion

  if (q.size() == 0)
    return;
  int front_num = q.front();
  q.pop();
  reverse_queue(q);
  q.push(front_num);
}

int main(int argc, char *argv[]) {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  print_que(q);
  reverse_queue(q);
  print_que(q);

  return 0;
}
