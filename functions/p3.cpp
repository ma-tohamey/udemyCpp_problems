#include <iostream>
using namespace std;

int operation_numbers = 0;

int menu() {
  int user_input = -1;
  cout << "1) Add 2 numbers\n";
  cout << "2) Subtract 2 numbers\n";
  cout << "3) Multiply 2 nubmers\n";
  cout << "4) Divide 2 numbers\n";
  cout << "5) End the program\n";

  cin >> user_input;
  bool not_valid_input = !(1 <= user_input && user_input <= 5);
  if (not_valid_input) {
    cout << "Not a valid input! Try again.";
    user_input = -1;
  }
  return user_input;
};

void read_2_numbers(double &a, double &b) { cin >> a >> b; }
void add_2_numbers(double a, double b) { cout << a + b << endl; };
void subtract_2_numbers(double a, double b) { cout << a - b << endl; };
void multiply_2_numbers(double a, double b) { cout << a * b << endl; };
void divide_2_numbers(double a, double b) {
  if (b == 0) {
    cout << "Don't divide by zero!" << endl;
  }
  cout << a / b << endl;
};

void calc() {

  double a, b;
  while (true) {
    int user_choice = menu();

    if (user_choice == 5) {
      cout << "operations had been done are: " << operation_numbers << endl;
      break;
    }

    operation_numbers++;

    read_2_numbers(a, b);
    if (user_choice == 1) {
      add_2_numbers(a, b);
    } else if (user_choice == 2) {
      subtract_2_numbers(a, b);
    } else if (user_choice == 3) {
      multiply_2_numbers(a, b);
    } else if (user_choice == 4) {
      divide_2_numbers(a, b);
    }
  }
}

int main(int argc, char *argv[]) {
  calc();
  return 0;
}
