#include <iostream>

int total_users = 0;

namespace OurSystem {
int total_users = 10;
}

namespace DownloadedSystem {
int total_users = 20;
}

namespace OurSystem {
const int size = 10;
}

int main(int argc, char *argv[]) {
  std::cout << OurSystem::total_users << std::endl;
  std::cout << DownloadedSystem::total_users << std::endl;
  std::cout << OurSystem::size << std::endl;
  std::cout << total_users << std::endl;
  return 0;
}
