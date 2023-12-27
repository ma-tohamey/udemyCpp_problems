#pragma once
#include "Admin.h"
#include "ExpediaFrontend.h"
#include <assert.h>

class AdminsManager {
private:
  Admin *admin = nullptr;

public:
  AdminsManager(User *&user);

  std::vector<std::string> &GetAdminMenu(std::vector<std::string> &Menu);
  bool HandelAdminChoice(ExpediaFrontend *systemFrontend, int userChoice);

  ~AdminsManager();
};
