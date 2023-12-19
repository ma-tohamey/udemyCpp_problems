#include "json.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::string jsonQuery;
  std::cin >> jsonQuery;

  json::JSON JsonObject = json::JSON::Load(jsonQuery);

  std::cout << JsonObject << std::endl;
  // for (auto &object : JsonObject.ObjectRange())
  //   std::cout << object.first << ": " << object.second << std::endl;
  return 0;
}
