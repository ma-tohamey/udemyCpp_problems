#include <iostream>
#include <string>

using namespace std;

const int MAX = 10000;

string names[MAX];
int ages[MAX], salaries[MAX] = {0}, current_employee = 0;
char gender[MAX];

// this one will print the menu
int menu() {
  int user_input = -1;
  cout << "Enter your choice:\n";
  cout << "1) Add new employee\n";
  cout << "2) Print all employees\n";
  cout << "3) Delete by age\n";
  cout << "4) Update salary by name\n";
  cout << "5) Exit\n";

  cin >> user_input;
  bool not_valid_choice = !(1 <= user_input && user_input <= 4);
  if (not_valid_choice) {
    cout << "Invalid input please try again. \n";
    user_input = -1;
  }

  return user_input;
};

// add new employee to the system
void add_employee() {
  cout << "Enter name: ";
  cin >> names[current_employee];

  cout << "Enter age: ";
  cin >> ages[current_employee];

  cout << "Enter salary: ";
  cin >> salaries[current_employee];

  cout << "Enter Gender (M/F): ";
  cin >> gender[current_employee];

  current_employee++;
  cout << endl;
};

// print all employees
void print_employee() {
  cout << "########################################\n";
  for (int i = 0; i < current_employee; i++) {
    if (salaries[i] != 0) {
      cout << names[i] << " " << ages[i] << " " << salaries[i] << " "
           << gender[i] << endl;
    }
  }
  cout << "########################################\n";
};

// delete employees by age
void delete_by_age() {
  cout << "Enter start and end age\n";
  int start_age, end_age;
  cin >> start_age >> end_age;

  for (int i = 0; i < current_employee; i++) {
    bool is_employee_and_in_target_range =
        salaries[i] && (start_age <= ages[i] && ages[i] <= end_age);
    if (is_employee_and_in_target_range) {
      salaries[i] = 0;
    }
  }
};

// update the salary for employee with name
void update_salary_by_name() {
  cout << "Enter the name and salary ";
  string name;
  int salary;
  cin >> name >> salary;

  for (int i = 0; i < current_employee; i++) {
    if (name == names[i]) {
      salaries[i] = salary;
    }
  }
};

void employee_system() {
  while (true) {
    int choice = menu();

    if (choice == 1) {
      add_employee();
    } else if (choice == 2) {
      print_employee();
    } else if (choice == 3) {
      delete_by_age();
    } else if (choice == 4) {
      update_salary_by_name();
    } else if (choice == 5) {
      break;
    }
  }
}
int main() {
  employee_system();
  return 0;
}
