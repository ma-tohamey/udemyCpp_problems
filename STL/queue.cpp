#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);

  // int first_item = q.front();
  // int last_item = q.back();

  cout << "first item: " << q.front() << endl;
  cout << "last item: " << q.back() << endl;
  q.pop();
  cout << "first item: " << q.front() << endl;
  cout << "last item: " << q.back() << endl;

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}
