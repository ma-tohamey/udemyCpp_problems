#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
using namespace std;

struct patient {
  string name;
  bool is_urgent;
  int id, spec;

  patient() {}
  patient(int _id, int _spec, string _name, bool _is_urgent) {
    id = _id;
    name = _name;
    is_urgent = _is_urgent;
    spec = _spec;
  }
};

int main(int argc, char *argv[]) {
  deque<int> dq{1, 2, 3, 4, 100};
  for (auto item : dq)
    cout << item << " ";
  cout << endl;

  cout << "fourth: " << dq[4] << endl;
  dq[4] = 101;
  dq.at(5) = 103;
  cout << "fourth: " << dq[4] << endl;

  deque<int>::iterator first_it = find(dq.begin(), dq.end(), 3);
  cout << *first_it << endl;             // printing the value
  cout << &first_it << endl;             // printing memory address
  cout << first_it - dq.begin() << endl; // getting the idx

  auto nd_it = find(dq.begin(), dq.end(), 7);
  auto rd_it = find(dq.begin(), dq.end(), 101);
  auto end = dq.end();
  cout << &nd_it << endl;
  cout << &end << endl;

  if (rd_it != dq.end())
    cout << "i found it" << endl;
  else
    cout << "i didn't found it" << endl;

  patient p1;
  p1.name = "mahmoud";
  p1.id = 151;
  p1.spec = 15;
  p1.is_urgent = 1;
  deque<patient> patient_que{p1, p1, p1};

  deque<patient>::iterator it = patient_que.begin();
  (it + 1)->name = "ahmed";
  (it + 1)->id = 161;
  (it + 1)->is_urgent = 0;
  (it + 1)->spec = 16;

  (it + 2)->name = "ali";
  (it + 2)->id = 171;
  (it + 2)->is_urgent = 1;
  (it + 2)->spec = 10;

  for (patient p : patient_que)
    cout << p.name << " " << p.is_urgent << " " << p.id << " " << p.spec
         << endl;
  return 0;
}
