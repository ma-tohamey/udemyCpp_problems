#include "../Headers/Customer.h"

Customer::Customer() { SetUserType(); }

bool Customer::SetUserType() {
  this->userType = "Customer";
  return true;
}

void Customer::Read(const std::string &userName) {
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

void Customer::ViewProfile() const {
  std::cout << "Customer Profile: " << GetName() << " (" << GetUserName()
            << ") - " << GetEmail() << std::endl;
}

Customer::~Customer() {}
