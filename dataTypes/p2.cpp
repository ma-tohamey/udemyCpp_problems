#include<iostream>

using namespace std;

int main()
{
  // st is student
  string st1, st2, st1Id, st2Id;
  double st1Grade, st2Grade; // double because you need to get average for grades

  cout << "What is student 1 name: ";
  cin >> st1;
  cout << "His id: ";
  cin >> st1Id;
  cout << "His math exam grade: ";
  cin >> st1Grade;

  cout << "What is student 2 name: ";
  cin >> st2;
  cout << "His id: ";
  cin >> st2Id;
  cout << "His math exam grade: ";
  cin >> st2Grade;

  cout << "\nStudents grades in math\n";
  cout << st1 << " (with id " << st1Id << ") got grade: " << st1Grade << "\n";
  cout << st2 << " (with id " << st2Id << ") got grade: " << st2Grade << "\n";
  cout << "Average grade is " << (st1Grade + st2Grade) / 2 << endl; 
}
