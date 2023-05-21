#include <iostream>
#include <queue>

using namespace std;

void print(priority_queue<int> &pq) {
  cout << "Priortiy Queue elements: ";
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  priority_queue<int> pq;
  pq.push(3);
  pq.push(5);
  pq.push(1);
  pq.push(7);
  pq.push(0);

  cout << pq.top() << endl;
  print(pq);
  return 0;
}
