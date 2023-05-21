#include <iostream>
#include <iterator>
#include <tuple>

using namespace std;

int main(int argc, char *argv[]) {

  tuple<string, int, char> player_info{"CR7", 7, 'N'};
  cout << "The first player we have here is: " << get<0>(player_info)
       << " he have number: " << get<1>(player_info)
       << " he playes now with team start with letter " << get<2>(player_info)
       << endl;

  return 0;
}
