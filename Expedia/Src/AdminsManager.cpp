#include "../Headers/AdminsManager.h"

AdminsManager::AdminsManager(User *&user) : admin(dynamic_cast<Admin *>(user)) {

  if (admin == nullptr) {
    std::cout << "Error: User is null pointer as input\n";
    assert(admin != nullptr);
  }
}

std::vector<std::string> &
AdminsManager::GetAdminMenu(std::vector<std::string> &Menu) {
  Menu.clear();
  Menu.push_back("View Profile");
  Menu.push_back("Admins Option 2");
  Menu.push_back("Admins Option 3");
  Menu.push_back("Admins Option 4");
  Menu.push_back("LogOut");
  return Menu;
};

bool AdminsManager::HandelAdminChoice(ExpediaFrontend *systemFrontend,
                                      int userChoice) {
  if (userChoice == 1) {
    admin->ViewProfile();
  } else if (userChoice == 2) {
  } else if (userChoice == 3) {
  } else if (userChoice == 4) {
  } else if (userChoice == 5) {
    return false;
  } else {
    systemFrontend->PrintInvalidUserChoiceMessage();
  }
  return true;
}
AdminsManager::~AdminsManager() {}
