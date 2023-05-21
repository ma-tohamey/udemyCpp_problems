#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int> &pq) {
  cout << "Priority Queue elements: ";
  while (!pq.empty()) {
    cout << pq.top() * -1 << " ";
    pq.pop();
  }
  cout << endl;
}
int main(int argc, char *argv[]) {
  priority_queue<int> pq;
  pq.push(-3);
  pq.push(-5);
  pq.push(-1);
  pq.push(-7);
  pq.push(0);

  print(pq);
  //
  // cout << sizeof(q) << endl;
  // cout << sizeof(int) << endl;
  //
  // for (int i = 0; i < 3; i++) {
  //   cout << q.front() << " ";
  //   q.pop();
  // }

  // cout << "Last element in Queue " << q.back() << endl;
  // cout << "Queue elements: ";
  // while (!q.empty()) {
  //   cout << q.front() << " ";
  //   q.pop();
  // }
  // cout << endl;
  //
  // queue<string> q_names;
  // q_names.push("mostafa");
  // string name = q_names.front();

  return 0;
}
