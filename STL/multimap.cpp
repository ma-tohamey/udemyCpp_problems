#include <cassert>
#include <ios>
#include <iostream>
#include <map>
#include <set>

struct MyArray {
  int salaries[3];
};

using namespace std;

int main(int argc, char *argv[]) {

  int arr[]{1, 2, 3};

  auto salPtr{arr};

  MyArray myarr{3, 4, 5};
  auto [actuall_arr] = myarr;

  for (int i : actuall_arr)
    cout << i << ' ';
  cout << endl;

  if (typeid(actuall_arr) == typeid(myarr.salaries))
    cout << "true" << endl;
  else
    cout << "false" << endl;

  // set<int> st{4, 20, 30, 30, 20};
  //
  // auto [iter1, is_inserted1] = st.insert(21);
  // cout << is_inserted1 << endl;
  // auto [iter2, is_inserted2] = st.insert(30);
  // cout << is_inserted2 << endl;
  //
  // if (auto [iter3, success] = st.insert(4); success) {
  //   cout << "yes 15 has been added to the set" << endl;
  // }
  //
  // for (int n : st)
  //   cout << n << ' ';
  // cout << endl;

  // multimap<int, int> mp;
  // mp = {{1, 40}, {1, 50}, {3, 60}};
  //
  // for (const auto &[key, value] : mp)
  //   cout << "key: " << key << " vlaue: " << value << endl;
  // cout << endl;
  //
  // auto [it_start, it_end] = mp.equal_range(3);
  //
  // for (; it_start != it_end; it_start++) {
  //   cout << it_start->first << ' ' << it_start->second << endl;
  // }
  // cout << endl;
  return 0;
}
