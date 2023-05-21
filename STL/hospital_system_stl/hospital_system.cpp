#include <deque>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

struct patient {
  string name;
  bool is_urgent;

  patient() {}

  patient(string _name, bool _is_urgent) {
    name = _name;
    is_urgent = _is_urgent;
  }
};

struct queue_line {
  deque<patient> patient_que;
  queue_line() {}

  void print_queue() {
    for (patient p : patient_que) {
      cout << p.name << ' ' << (p.is_urgent ? "urgent" : "regular");
    }
  }
};

struct hospital_system {
  vector<queue_line> hospital_spec;
  hospital_system() { hospital_spec = vector<queue_line>(MAX_SPECIALIZATION); }

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

    if (hospital_spec[spec_num].patient_que.size() < MAX_QUEUE) {
      if (new_patient.is_urgent)
        hospital_spec[spec_num].patient_que.push_front(new_patient);
      else
        hospital_spec[spec_num].patient_que.push_back(new_patient);
    } else {
      cout << "Sorry we can't add more patients for this specialization\n";
    }
  }
  void Print_all_patients() {
    for (int i = 0; i < MAX_SPECIALIZATION; i++)
      if (hospital_spec[i].patient_que.size() > 0) {
        cout << "******************************************\n";
        cout << "There are " << hospital_spec[i].patient_que.size()
             << " patients in specialization " << i << endl;
        hospital_spec[i].print_queue();
      }
  }
  void Get_next_patient() {
    int spec_num;
    cout << "Enter specialization: ";
    cin >> spec_num;

    if (hospital_spec[spec_num].patient_que.size() > 0) {
      string current_patient = hospital_spec[spec_num].patient_que.front().name;
      hospital_spec[spec_num].patient_que.pop_front();
      cout << current_patient << " please go with the Dr.\n";
    } else {
      cout << "No patients at the moment. Have rest, Dr.\n";
    }
  }
};
int main(int argc, char *argv[]) {
  hospital_system hospital;
  hospital.run();
  return 0;
}
