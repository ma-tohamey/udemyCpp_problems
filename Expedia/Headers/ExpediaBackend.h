#pragma once
#include "../Headers/ExpediaFrontend.h"
#include "../Headers/UsersManager.h"
#include "../Headers/Utilities.h"

class ExpediaBackend {
private:
  ExpediaFrontend *systemFrontend;
  UsersManager *usersManager;

  std::vector<std::string> Menu;
  int userChoice;

  ExpediaBackend(const ExpediaBackend &) = delete;
  void operator=(const ExpediaBackend &) = delete;

public:
  ExpediaBackend();
  void run();
  ~ExpediaBackend();
};
