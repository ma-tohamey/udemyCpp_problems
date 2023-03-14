#include <iostream>
using namespace std;

struct employee {
  string name;
  int age, salary;
  char gender;
};

int main(int argc, char *argv[]) {
  employee employees[100];
  employees[0].name = "mahmoud";
  employees[0].age = 23;
  cout << employees[0].name << " " << employees[0].age << endl;

  return 0;
}
