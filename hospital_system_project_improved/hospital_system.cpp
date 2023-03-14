#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

struct patient {
  string name;
  bool is_urgent;

  patient(){};
  patient(string _name, bool _is_urgent) {
    name = _name;
    is_urgent = _is_urgent;
  }
};

struct queue_line {
  patient patients[MAX_QUEUE];
  int len;
  queue_line() { len = 0; }

  void add_end(patient &reg_patient) {
    patients[len] = reg_patient;
    len++;
  };

  void add_front(patient &urg_patient) {
    for (int i = len; i > 0; i--)
      patients[i] = patients[i - 1];
    patients[0] = urg_patient;
    len++;
  };

  string remove_front() {
    string chosen_patient = patients[0].name;
    len--;
    for (int i = 0; i < len; i++)
      patients[i] = patients[i + 1];
    return chosen_patient;
  };
  void print_queue() {
    for (int i = 0; i < len; i++) {

      string patient_status = "regular";
      if (patients[i].is_urgent)
        patient_status = "urgent";

      cout << patients[i].name << " " << patient_status << endl;
    }
  };
};

struct hospital_system {
  queue_line spec_queue[MAX_SPECIALIZATION];

  void run() {
    while (true) {
      int user_choice = menu();

      if (user_choice == 1)
        Add_new_patient();
      else if (user_choice == 2)
        Print_all_patients();
      else if (user_choice == 3)
        Get_next_patient();
      else if (user_choice == 4)
        return;
    }
  }

  int menu() {
    cout << "\nEnter your choice: \n";
    cout << "1) Add new patient\n";
    cout << "2) Print all patient\n";
    cout << "3) Get next patients\n";
    cout << "4) Exit\n";
    int user_choice;
    cin >> user_choice;
    return user_choice;
  }

  void Add_new_patient() {
    int spec_num;
    patient new_patient;
    cout << "Enter specialization, name, status: ";
    cin >> spec_num >> new_patient.name >> new_patient.is_urgent;

    if (spec_queue[spec_num].len < MAX_QUEUE) {
      if (new_patient.is_urgent)
        spec_queue[spec_num].add_front(new_patient);
      else
        spec_queue[spec_num].add_end(new_patient);
    } else {
      cout << "Sorry we can't add more patients for this specialization\n";
    }
  };
  void Print_all_patients() {
    for (int i = 0; i < MAX_SPECIALIZATION; i++)
      if (spec_queue[i].len > 0) {
        cout << "******************************************\n";
        cout << "There are " << spec_queue[i].len
             << " patients in specialization " << i << endl;
        spec_queue[i].print_queue();
      }
  };
  void Get_next_patient() {
    int spec_num;
    cout << "Enter specialization: ";
    cin >> spec_num;

    if (spec_queue[spec_num].len > 0) {
      string current_patient = spec_queue[spec_num].remove_front();
      cout << current_patient << " please go with the Dr.\n";
    } else {
      cout << "No patients at the moment. Have rest, Dr.\n";
    }
  };
};
int main(int argc, char *argv[]) {
  hospital_system hospital;
  hospital.run();
  return 0;
}
