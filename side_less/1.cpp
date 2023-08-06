#include <iostream>
#include <sstream>
#include <string>

int toint(std::string str) {
  std::istringstream iss(str);
  int ret;
  iss >> ret;
  return ret;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Error: Please pass string and integer." << std::endl;
    return 0;
  }

  std::string path = argv[1];
  // int limit = std::stoi(argv[2]);
  int lmt = std::atoi(argv[2]);

  std::cout << path << std::endl;
  // std::cout << limit << std::endl;
  std::cout << lmt << std::endl;
  return 0;
}
