#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
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

struct spec_queue {
  deque<patient> patients_queue;
  spec_queue() {}

  void print_q() {
    for (auto p : patients_queue)
      cout << p.name << " " << (p.is_urgent ? "urgent" : "regular") << endl;
    cout << endl;
  }
};

struct hospital_system {

  vector<spec_queue> hospital_specializations;
  hospital_system() {
    hospital_specializations = vector<spec_queue>(MAX_SPECIALIZATION);
  }

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
    int que_size = hospital_specializations[spec_num].patients_queue.size();
    if (que_size < MAX_QUEUE) {
      if (new_patient.is_urgent) {
        hospital_specializations[spec_num].patients_queue.push_front(
            new_patient);
      } else
        hospital_specializations[spec_num].patients_queue.push_back(
            new_patient);
    } else {
      cout << "Sorry we can't add more patients for this specialization\n";
    }
  }

  void Print_all_patients() {
    for (int i = 0; i < MAX_SPECIALIZATION; i++)
      if (hospital_specializations[i].patients_queue.size() > 0) {
        cout << "******************************************\n";
        cout << "There are "
             << hospital_specializations[i].patients_queue.size()
             << " patients in specialization " << i << endl;
        hospital_specializations[i].print_q();
        // for (auto patient : hospital_specializations[i].patients_queue)
        //   cout << patient.name << " "
        //        << (patient.is_urgent ? "urgent" : "regular") << endl;
      }
  }
  void Get_next_patient() {
    int spec_num;
    cout << "Enter specialization: ";
    cin >> spec_num;

    if (hospital_specializations[spec_num].patients_queue.size() > 0) {
      string current_patient =
          hospital_specializations[spec_num].patients_queue.front().name;
      hospital_specializations[spec_num].patients_queue.pop_front();
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
