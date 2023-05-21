#include <iostream>
#include <tuple>

using namespace std;

int main(int argc, char *argv[]) {
  tuple<char, int, string> t1;
  t1 = make_tuple('M', 7, "Mahmoud");

  cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
  get<2>(t1) = "Mr.Dragon";
  cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

  char new_char{'A'};
  int new_value{10};
  string new_string{"Mr.Unknown"};

  // tie(new_char, new_value, new_string) = t1;
  t1 = tie(new_char, new_value, new_string);
  cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

  tuple<double> t2;
  t2 = make_tuple(10.5);
  tuple_cat(t1, t2);
  // auto t2 = tuple_cat(t1, make_tuple(10.5));

  cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << " "
       << get<3>(t2);
  return 0;
}
