#pragma once
#include "AdminsManager.h"
#include "CustomersManager.h"
#include <map>

class UsersManager {
private:
  std::map<std::string, User *> usersMap;

  ExpediaFrontend *systemFrontend;
  User *currentUser = nullptr;
  CustomersManager *customersManager = nullptr;
  AdminsManager *adminsManager = nullptr;
  UsersManager(const UsersManager &) = delete;
  void operator=(const UsersManager &) = delete;

public:
  UsersManager(ExpediaFrontend *expediaFrontend);

  void LoadDatabase();

  bool IsSignedUser();

  void DoLogIn();
  void DoSignUp(const std::string &userType);

  bool HandelUserChoice(ExpediaFrontend *, int userChoice);

  std::vector<std::string> &GetMenu(std::vector<std::string> &Menu);

  void FreeLoadedData();
  ~UsersManager();
};
