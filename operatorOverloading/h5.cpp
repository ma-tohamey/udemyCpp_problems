#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

class MyMap {
private:
  std::vector<std::string> vec_strs;
  std::vector<int> vec_ints;
  int iteratorPos = 0;

public:
  MyMap() {}

  int &operator[](const std::string &StrKey) {
    for (int i = 0; i < vec_strs.size(); ++i) {
      if (vec_strs[i] == StrKey) // then just update it's value
        return vec_ints[i];
    }
    // not found before then it's new key
    vec_strs.push_back(StrKey);
    vec_ints.push_back(0);
    return vec_ints.back();
  }

  std::vector<std::string> operator[](const int value) {
    std::vector<std::string> keys;
    for (int i = 0; i < vec_ints.size(); ++i)
      if (vec_ints[i] == value)
        keys.push_back(vec_strs[i]);

    std::sort(keys.begin(), keys.end());
    return keys;
  }

  void Reset_iterator() { iteratorPos = 0; }

  bool HasNext() {
    if (iteratorPos < vec_strs.size())
      return true;
    return false;
  }

  std::pair<std::string, int> GetNext() {
    std::pair<std::string, int> result =
        std::make_pair(vec_strs[iteratorPos], vec_ints[iteratorPos]);
    ++iteratorPos;
    return result;
  }

  void Clear() {
    vec_ints.clear();
    vec_strs.clear();
  }
};

int main(int argc, char *argv[]) {
  // some code
  MyMap map;
  map["mostafa"] = 20;
  map["mostafa"] = 40;
  map["sayed"] = 20;
  map["ali"] = 20;

  std::cout << map["mostafa"] << std::endl;

  std::vector<std::string> v = map[20];
  for (auto s : v)
    std::cout << s << std::endl;

  map.Reset_iterator();

  while (map.HasNext()) {
    auto p = map.GetNext();
    std::cout << p.first << " " << p.second << std::endl;
  }

  map.Clear();
  return 0;
}
