// User.cpp
#include "../Headers/User.h"

bool User::SetName(const std::string &name) {
  if (name != "") {
    this->name = name;
    return true;
  }
  return false;
}
bool User::SetUserName(const std::string &userName) {
  if (userName != "") {
    this->userName = userName;
    return true;
  }
  return false;
}

bool User::SetPassword(const std::string &password) {
  if (password != "") {
    this->password = password;
    return true;
  }
  return false;
}
bool User::SetEmail(const std::string &email) {
  if (email != "") {
    this->email = password;
    return true;
  }
  return false;
};
// Empty implementations for pure virtual functions

const std::string &User::GetName() const { return name; }
const std::string &User::GetUserName() const { return userName; }
const std::string &User::GetPassword() const { return password; }
const std::string &User::GetEmail() const { return email; }
const std::string &User::GetUserType() const { return userType; }

void User::logout() {
  name = "";
  userName = "";
  password = "";
  email = "";
  userType = "";
}

bool User::SetUserType() { return false; }

void User::Read(const std::string &userName) {}
void User::ViewProfile() const {}

User::~User() {
  // Implement any cleanup or additional steps needed for the destructor
}
