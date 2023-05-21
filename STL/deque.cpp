#include <deque>
#include <iostream>

using namespace std;

void print_front(deque<int> &dq) {
  cout << "Queue elements (front): ";
  while (!dq.empty()) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  cout << endl;
}

void print_back(deque<int> dq) {
  cout << "Queue elements (back): ";
  while (!dq.empty()) {
    cout << dq.back() << " ";
    dq.pop_back();
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  deque<int> q;
  q.push_back(20);
  q.push_back(30);
  q.push_back(40);
  q.push_front(10);
  q.push_back(50);
  q.push_back(0);

  cout << q.front() << endl;

  deque<int> copy = q;

  print_back(q);
  print_front(q);
  print_front(q);

  cout << copy.size() << endl;
  cout << copy[1] << endl;
  cout << copy.at(1) << endl;

  copy.clear();
  cout << copy.size() << endl;

  return 0;
}

// #include <deque>
// #include <iostream>
// #include <queue>
// using namespace std;
//
// void print_back(deque<int> &q) {
//   cout << "Queue elements (back): ";
//   while (!q.empty()) {
//     cout << q.back() << " ";
//     q.pop_back();
//   }
//   cout << endl;
// }
//
// void print_front(deque<int> &q) {
//   cout << "Queue elements (front): ";
//   while (!q.empty()) {
//     cout << q.front() << " ";
//     q.pop_front();
//   }
//   cout << endl;
// }
//
// int main(int argc, char *argv[]) {
//   deque<int> dq;
//   queue<int> q;
//   priority_queue<int> pq;
//
//   dq.push_back(20);
//   dq.push_back(30);
//   dq.push_back(40);
//   dq.push_front(10);
//   dq.push_back(50);
//   dq.push_front(0);
//
//   deque<int> copy = dq;
//   cout << copy.at(1) << endl;
//   print_back(dq);
//   print_front(copy);
//   print_front(dq);
//
//   return 0;
// }
