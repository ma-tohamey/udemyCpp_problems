#include "../Headers/User.h"

// Empty implementations for pure virtual functions
bool User::SetName(std::string name) { return false; }
bool User::SetUserName(std::string userName) { return false; }
bool User::SetPassword(std::string password) { return false; }
bool User::SetEmail(std::string email) { return false; }

const std::string &User::GetName() const {
  static std::string empty;
  return empty;
}
const std::string &User::GetUserName() const {
  static std::string empty;
  return empty;
}
const std::string &User::GetPassword() const {
  static std::string empty;
  return empty;
}
const std::string &User::GetEmail() const {
  static std::string empty;
  return empty;
}
void User::ViewProfile() const {}
void User::Read(const std::string &userName) {}
std::string User::GetUserType() const { return ""; }
