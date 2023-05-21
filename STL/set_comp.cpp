#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

struct employee {
  int num1, num2;
  string str;

  employee(int a, int b, string name) { num1 = a, num2 = b, str = name; }

  bool operator<(const employee &rhs) const {
    return tie(num1, str, num2) < tie(rhs.num1, rhs.str, rhs.num2);
  }
  bool operator>(const employee &rhs) const {
    return tie(num1, str, num2) > tie(rhs.num1, rhs.str, rhs.num2);
  }
};

int main(int argc, char *argv[]) {
  set<employee> s;
  employee emp1 = employee(10, 35, "mostafa");
  employee emp2 = employee(7, 15, "ali");
  employee emp3 = employee(10, 17, "ziad");
  employee emp4 = employee(10, 20, "mostafa");

  s.insert(emp1);
  s.insert(emp2);
  s.insert(emp3);
  s.insert(emp4);

  for (auto emp : s)
    cout << emp.num1 << " " << emp.str << " " << emp.num2 << endl;

  if (emp1 < emp2)
    cout << emp1.num1 << " " << emp1.str << " " << emp1.num2 << endl;
  return 0;
}
