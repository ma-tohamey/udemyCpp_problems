#include <iostream>
#include <string>
using namespace std;

void Add_urgent(int start_idx, int vacancy_place, string names[],
                string patient_name) {
  if (vacancy_place == start_idx) {
    names[start_idx] = patient_name;
    return;
  }
  names[vacancy_place] = names[vacancy_place - 1];
  Add_urgent(start_idx, vacancy_place - 1, names, patient_name);
};

void rearranging_queue(string names[], int start_idx, int end_idx) {
  if (start_idx == end_idx)
    return;

  names[start_idx] = names[start_idx + 1];
  rearranging_queue(names, start_idx + 1, end_idx);
};

void Print_menu() {
  cout << "\nEnter your choice:\n";
  cout << "1) Add new patient\n";
  cout << "2) Print all patients\n";
  cout << "3) Get next patient\n";
  cout << "4) Exit\n";
}

void Add_new_patient(int specializations[], string names[]) {
  int specialization;
  bool is_urgent;
  string patient_name;

  cout << "Enter specialization, name, status: ";
  cin >> specialization >> patient_name >> is_urgent;
  cout << endl;

  // number of patients in the current specialization
  // get the starting idx for the current specialization from names[array]
  int n_of_patients = specializations[specialization];
  int start_idx = specialization - 1 * 5;

  if (n_of_patients < 5) {
    // by adding starting idx and number of current patients will give you
    // vacancy idx
    int vacancy_place = start_idx + n_of_patients;
    if (is_urgent) {
      // add urgent patient
      // increasing the patients in the current specialization by 1
      Add_urgent(start_idx, vacancy_place, names, patient_name);
      specializations[specialization]++;
    } else {
      // adding a regular patient at the vacancy place
      // increasing the patients in the current specialization by 1
      names[vacancy_place] = patient_name;
      specializations[specialization]++;
    }
  } else {
    // if there is no vacancy places in the specialization print sorry message
    cout << "Sorry we can't add more patients for this specialization\n"
         << endl;
    return;
  }
};

void Print_all_patient(int specializations[], string names[]) {
  for (int i = 0; i < 21; i++) {
    if (specializations[i]) {
      int start_idx = i - 1 * 5;
      int end_idx = start_idx + specializations[i];

      cout << "**********************************************\n";
      cout << "There are " << specializations[i]
           << " patients in specialization " << i << endl;
      for (int j = start_idx; j < end_idx; j++) {
        cout << names[j] << endl;
      }
      cout << endl << endl;
    }
  }
};

void Get_next_patient(int specializations[], string names[]) {
  int specialization_number;
  cout << "Enter specialization: ";
  cin >> specialization_number;

  if (specializations[specialization_number]) {
    int patient_idx = specialization_number - 1 * 5;
    cout << names[patient_idx] << " please go with the Dr\n";
    specializations[specialization_number]--;
    int end_idx = patient_idx + specializations[specialization_number];
    rearranging_queue(names, patient_idx, end_idx);
  } else {
    cout << "No patients at the moment. Have rest, Dr\n";
  }
};

int main(int argc, char *argv[]) {

  // initializing the hospital environment;
  // you have just 20 specialization in the hospital
  // and only 5 available chairs for the patients
  int specializations[21] = {0};
  // so 20 * 5 = 100 vacancy place in the whole hospital

  // and also i could make it 2d array but i am a lazy person;
  string names[101];

  while (true) {
    int user_choice;
    Print_menu();
    cin >> user_choice;

    if (user_choice == 1)
      Add_new_patient(specializations, names);
    else if (user_choice == 2)
      Print_all_patient(specializations, names);
    else if (user_choice == 3)
      Get_next_patient(specializations, names);
    else if (user_choice == 4)
      return 0;
  }
  return 0;
}
