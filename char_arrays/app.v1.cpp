#include <iostream>
#include <string>

using namespace std;

int main() {
  int const MAX = 10000;

  string names[MAX];
  int ages[MAX], salary[MAX];
  char gender[MAX];

  // i can use ages or salary insted of is_emplyee and save more mem;
  bool is_emplyee[MAX] = {0};
  int emplyess_number = 0;

  while (true) {
    cout << "Enter your choice:" << '\n';
    cout << "1) Add new emplyee" << '\n';
    cout << "2) Print all emplyees" << '\n';
    cout << "3) Delete by age" << '\n';
    cout << "4) Update Salary by name" << '\n';
    cout << "5) Exit Program" << '\n';
    cout << "Your choice: ";

    string user_input;
    cin >> user_input;

    if (user_input == "1") {
      for (int i = 0; i < MAX; i++) {
        if (!is_emplyee[i]) {
          cout << "------------------------------\n";
          cout << "Enter name: ";
          cin >> names[i];
          cout << "Enter age: ";
          cin >> ages[i];
          cout << "Enter Salary: ";
          cin >> salary[i];
          cout << "Enter gender (M/F): ";
          cin >> gender[i];
          cout << "------------------------------\n";
          emplyess_number++;
          is_emplyee[i] = true;
          cout << "\n";
          cout << "---> " << names[i]
               << " has been add to the employee system.\n";
          cout << "------------------------------------\n";
          cout << "| Total of current emplyees are: " << emplyess_number
               << " |\n";
          cout << "------------------------------------\n";
          cout << "\n";
          break;
        }
      }
    } else if (user_input == "2") {
      int printed_employees = 0;
      cout << "----------------------------------------------------------------"
              "-----------\n";
      if (emplyess_number == 0) {
        cout << "| There is no emplyees yet use choice 1 to add new emplyee to "
                "the system. |\n";
      }

      for (int i = 0; i < MAX; i++) {
        if (is_emplyee[i]) {
          cout << names[i] << " " << ages[i] << " " << salary[i] << " "
               << gender[i] << "\n";
          printed_employees++;
        }
        if (printed_employees == emplyess_number) {
          break;
        }
      }
      cout << "----------------------------------------------------------------"
              "-----------\n";
    } else if (user_input == "3") {
      int start_age, end_age;
      cout << "---------------------------------\n";
      cout << "| Enter start and end age: ";
      cin >> start_age >> end_age;
      cout << "------------------------------\n";

      for (int i = 0; i < MAX; i++) {
        if (is_emplyee[i] && (start_age <= ages[i] && ages[i] <= end_age)) {
          is_emplyee[i] = false;
          emplyess_number--;
          cout << "---> " << names[i]
               << " has been deleted from the employee system.\n";
          cout << "------------------------------------\n";
          cout << "| Total of current emplyees are: " << emplyess_number
               << " |\n";
          cout << "------------------------------------\n";
        }
      }
    } else if (user_input == "4") {
      cout << "-----------------------------------------\n";
      cout << "| Enter the name and salary ";
      string employee_name;
      int new_salary;
      cin >> employee_name >> new_salary;
      cout << "-----------------------------------------\n";

      for (int i = 0; i < MAX; i++) {
        if (is_emplyee[i] && employee_name == names[i]) {
          int old_salary = salary[i];
          salary[i] = new_salary;
          cout << "---> " << names[i] << " has been salary update from "
               << old_salary << " to " << new_salary << ".\n\n";
          break;
        }
      }
    } else if (user_input == "5") {
      return 0;
    } else {
      cout << "Invalid choice please Try again !\n";
    }
  }
  return 0;
}
