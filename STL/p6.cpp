#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print_q(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

void reverse_queue(queue<int> &q) {
  stack<int> s;
  // while (!q.empty()) {
  //   s.push(q.front());
  //   q.pop();
  // }
  if (q.empty())
    return;
  int front_num = q.front();
  q.pop();
  reverse_queue(q);
  q.push(front_num);

  // while (!s.empty()) {
  //   q.push(s.top());
  //   s.pop();
  // }
}

int main(int argc, char *argv[]) {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  print_q(q);
  reverse_queue(q);
  print_q(q);
  return 0;
}
