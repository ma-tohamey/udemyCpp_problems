#include "../Headers/CustomersManager.h"

CustomersManager::CustomersManager(User *&user)
    : customer(dynamic_cast<Customer *>(user)) {

  if (customer == nullptr) {
    std::cout << "Error: User is null pointer as input\n";
    assert(customer != nullptr);
  }
}

std::vector<std::string> &
CustomersManager::GetCustomerMenu(std::vector<std::string> &Menu) {
  Menu.clear();
  Menu.push_back("View Profile");
  Menu.push_back("Make Itinerary");
  Menu.push_back("list my itineraries");
  Menu.push_back("Logout");
  return Menu;
};

bool CustomersManager::HandelCustomerChoice(ExpediaFrontend *systemFrontend,
                                            int userChoice) {

  if (userChoice == 1) {
    customer->ViewProfile();
  } else if (userChoice == 2) {

  } else if (userChoice == 3) {
  } else if (userChoice == 4) {
    return false;
  } else {
    systemFrontend->PrintInvalidUserChoiceMessage();
  }
  return true;
};

CustomersManager::~CustomersManager() {}
