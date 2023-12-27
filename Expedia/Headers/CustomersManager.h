#pragma once
#include "Customer.h"
#include "ExpediaFrontend.h"
#include <assert.h>
#include <vector>

class CustomersManager {
private:
  Customer *customer = nullptr;

public:
  CustomersManager(User *&user);

  std::vector<std::string> &GetCustomerMenu(std::vector<std::string> &Menu);
  bool HandelCustomerChoice(ExpediaFrontend *systemFrontend, int userChoice);

  ~CustomersManager();
};
