
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
}
