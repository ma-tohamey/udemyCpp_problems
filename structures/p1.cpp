#include <iostream>
using namespace std;

struct queue {
  int queue_line[11];
  int idx;

  queue() { idx = 0; }

  void add_end(int value) {
    // queue_line[idx] = value;
    // idx++;
    // better way to write it
    queue_line[idx++] = value;
  };
  void add_front(int value) {
    for (int i = idx + 1; i > 0; i--)
      queue_line[i] = queue_line[i - 1];
    queue_line[0] = value;
    idx++;
  };
  int remove_front() {
    int removed_value = queue_line[0];
    for (int i = 0; i < idx; i++)
      queue_line[i] = queue_line[i + 1];
    idx--;
    return removed_value;
  };
  void print() {
    for (int i = 0; i < idx; i++)
      cout << queue_line[i] << " ";
    cout << endl;
  };
};
int main(int argc, char *argv[]) {
  queue my_queue;

  my_queue.add_end(10);
  my_queue.add_end(20);
  my_queue.add_end(30);
  my_queue.print();

  my_queue.add_front(1);
  my_queue.add_front(4);
  my_queue.print();

  cout << my_queue.remove_front() << endl;

  my_queue.print();
  return 0;
}
