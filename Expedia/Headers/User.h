#pragma once
#include <iostream>

class User {
protected:
  std::string name;
  std::string userName;
  std::string password;
  std::string email;
  std::string userType;

public:
  User() : name(""), userName(""), password(""), email(""), userType(""){};

  User(const User &) = delete;
  void operator=(const User &) = delete;

  bool SetName(const std::string &name);
  bool SetUserName(const std::string &userName);
  bool SetPassword(const std::string &password);
  bool SetEmail(const std::string &email);

  const std::string &GetName() const;
  const std::string &GetUserName() const;
  const std::string &GetPassword() const;
  const std::string &GetEmail() const;
  const std::string &GetUserType() const;

  void logout();

  virtual bool SetUserType();
  virtual void Read(const std::string &userName);
  virtual void ViewProfile() const;

  virtual ~User();
};
