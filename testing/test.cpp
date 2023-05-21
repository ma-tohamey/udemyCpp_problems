#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> v{1, 2, 3, 4, 5, 6};
  cout << "Size: " << v.size() << endl;
  cout << "Capacity: " << v.capacity() << endl;

  v.insert(v.begin(), 55);

  cout << *min_element(v.begin(), v.end()) << endl;
  cout << *max_element(v.begin(), v.end()) << endl;

  vector<int>::iterator it = v.begin();

  v.resize(2);

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    cout << *it << " ";
  cout << endl;

  cout << *min_element(v.begin(), v.end()) << endl;

  for (auto it : v)
    cout << it << " ";
  cout << endl;

  v.shrink_to_fit();

  for (auto it : v)
    cout << it << " ";
  cout << endl;

  cout << "Size: " << v.size() << endl;
  cout << "Capacity: " << v.capacity() << endl;
  return 0;
}
