#include <iostream>
using namespace std;

// كنت مبضون جدا وانا بحل المسائله دي مع انها تافه جدا الصراحه بس اوك هعديها
// المره دي
// مليار في الميه فيه تحسينات بسيطه ممكن تحصل في الكود
int main() {
  string str_number;
  cin >> str_number;
  int number_length = str_number.size();
  int number, reminder = 0;

  for (int i = number_length - 1; i >= 0; i--) {
    number = str_number[i] - '0';

    if (i >= number_length - 4) {
      number += 5;
    }
    number += reminder;
    reminder = number / 10;
    str_number[i] = (number % 10) + '0';
  }
  if (reminder) {
    cout << 1;
  }
  cout << str_number << endl;
  return 0;
}
