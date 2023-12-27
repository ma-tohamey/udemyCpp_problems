#include "../Headers/Admin.h"

Admin::Admin() { SetUserType(); }

bool Admin::SetUserType() {
  this->userType = "Admin";
  return true;
}

void Admin::Read(const std::string &userName) {

  SetUserName(userName);

  std::string str;

  std::cout << "Enter password: ";
  std::cin >> str;
  SetPassword(str);

  std::cout << "Enter name: ";
  std::cin >> str;
  SetName(str);

  std::cout << "Enter email: ";
  std::cin >> str;
  SetEmail(str);
}

void Admin::ViewProfile() const {
  std::cout << "Admin Profile: " << GetName() << " (" << GetUserName() << ") - "
            << GetEmail() << std::endl;
}

Admin::~Admin() {}
