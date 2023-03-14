#include <iostream>
using namespace std;

struct full_name {
  string first, middle, last;

  void read_full_name() {
    cout << "please enter your full name ";
    cin >> first >> middle >> last;
  }
};
struct employee {
  full_name emplyee_name;
  int age, salary;
  char gender;

  void read_employee() {
    emplyee_name.read_full_name();
    cout << "Enter emplyee age, salary and gender: ";
    cin >> age >> salary >> gender;
  }

  void print_employee() {
    cout << "\n"
         << emplyee_name.first << " has " << age
         << " years old and his salary is : " << salary << endl;
  }

  void change_age_to(int new_age) { age = new_age; }

  int get_age() { return age; }
};

int main(int argc, char *argv[]) {
  employee first_emp;
  first_emp.read_employee();
  first_emp.print_employee();
  return 0;
}
