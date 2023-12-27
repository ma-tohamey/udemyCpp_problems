#include "../Headers/UsersManager.h"

UsersManager::UsersManager(ExpediaFrontend *systemFrontend)
    : systemFrontend(systemFrontend) {
  LoadDatabase();
}

void UsersManager::LoadDatabase() {
  std::cout << "UsersManager: LoadDatabase\n";

  FreeLoadedData();

  // Some "Dummy Data" for simplicity
  Admin *admin_user = new Admin();
  admin_user->SetUserName("mostafa");
  admin_user->SetPassword("111");
  admin_user->SetEmail("mostafa@gmail.com");
  // admin_user->SetIsLibraryAdmin(false);
  // admin_user->SetUserType("Admin");
  admin_user->SetName("mostafa Saad Ibrahim");
  usersMap[admin_user->GetUserName()] = admin_user;

  Customer *customrUser = new Customer();
  customrUser->SetUserName("asmaa");
  customrUser->SetPassword("222");
  customrUser->SetEmail("asmaa@gmail.com");
  // customrUser->SetUserType("Customer");
  // user1->SetIsLibraryAdmin(true);
  customrUser->SetName("Asmaa Saad Ibrahim");
  usersMap[customrUser->GetUserName()] = customrUser;

  // DebitCard *debitCard = new DebitCard();
  // debitCard->SetOwnerName(customrUser->GetName());
  // debitCard->SetCardNumber("11-22-33-44");
  // debitCard->SetExpiryDate("11/20");
  // debitCard->SetSecurityCode(111);
  // debitCard->SetBillingAddress("111 hello st, BC, Canada");
  // customrUser->AddPaymentCard(*debitCard);
  //
  // CreditCard *creditCard = new CreditCard();
  // creditCard->SetOwnerName(customrUser->GetName());
  // creditCard->SetCardNumber("22-11-03-44");
  // creditCard->SetExpiryDate("11/25");
  // creditCard->SetSecurityCode(1117);
  // customrUser->AddPaymentCard(*creditCard);
  // userame_userobject_map[customrUser->GetUserName()] = customrUser;
}

bool UsersManager::IsSignedUser() {
  if (currentUser == nullptr || currentUser->GetUserType() == "")
    return false;
  return true;
}

void UsersManager::DoLogIn() {
  // LoadDatabase();
  while (true) {
    std::string userName, password;
    std::cout << "Enter user user_name & password: ";
    std::cin >> userName >> password;

    if (!usersMap.count(userName)) {
      std::cout << "\nInvalid user user_name or password. Try again\n\n";
      continue;
    }

    currentUser = usersMap.find(userName)->second;

    if (password != currentUser->GetPassword()) {
      std::cout << "\nInvalid user user_name or password. Try again\n\n";
      continue;
    }

    if (customersManager == nullptr && currentUser->GetUserType() == "Customer")
      customersManager = new CustomersManager(currentUser);
    else if (adminsManager == nullptr && currentUser->GetUserType() == "Admin")
      adminsManager = new AdminsManager(currentUser);

    break;
  }
}

void UsersManager::DoSignUp(const std::string &userType) {
  // LoadDatabase();
  std::string userName;
  while (true) {
    std::cout << "Enter user name. (No spaces): ";
    std::cin >> userName;

    if (usersMap.count(userName))
      std::cout << "Already used. Try again\n";
    else
      break;
  }

  if (userType == "Customer") {
    currentUser = new Customer;
    customersManager = new CustomersManager(currentUser);
  } else if (userType == "Admin") {
    currentUser = new Admin;
    adminsManager = new AdminsManager(currentUser);
  }

  currentUser->Read(userName);
  usersMap[currentUser->GetUserName()] = currentUser;
}

bool UsersManager::HandelUserChoice(ExpediaFrontend *systemFrontend,
                                    int userChoice) {
  if (!IsSignedUser()) {
    if (userChoice == 1) {
      DoLogIn();
    } else if (userChoice == 2) {
      DoSignUp("Customer");
    } else if (userChoice == 3) {
      DoSignUp("Admin");
    } else if (userChoice == 4) {
      systemFrontend->PrintExitingMessage();
      return false;
    }

    else {
      systemFrontend->PrintInvalidUserChoiceMessage();
      return true;
    }

    systemFrontend->PrintWelcomingMessage(currentUser->GetName(),
                                          currentUser->GetUserType());
  }

  else
    // if the user choice handler return false it means logout ==> so move
    // current user to null and delete it's manager

    if (currentUser->GetUserType() == "Customer") {
      if (!customersManager->HandelCustomerChoice(systemFrontend, userChoice)) {
        systemFrontend->PrintLogoutMessage(currentUser->GetUserName());
        currentUser = nullptr;
        delete customersManager;
        customersManager = nullptr;
      }
    }

    else if (currentUser->GetUserType() == "Admin") {
      if (!adminsManager->HandelAdminChoice(systemFrontend, userChoice)) {
        systemFrontend->PrintLogoutMessage(currentUser->GetUserName());
        currentUser = nullptr;
        delete adminsManager;
        adminsManager = nullptr;
      }
    }
  return true;
}

std::vector<std::string> &
UsersManager::GetMenu(std::vector<std::string> &Menu) {
  if (IsSignedUser()) {
    std::string UserType{currentUser->GetUserType()};
    if (UserType == "Customer") {
      customersManager->GetCustomerMenu(Menu);
      return Menu;
    }

    else if (UserType == "Admin") {
      adminsManager->GetAdminMenu(Menu);
      return Menu;
    }
  }
  Menu.clear();
  Menu.push_back("Login");
  Menu.push_back("Sign Up As Customer");
  Menu.push_back("Sign Up As Admin");
  Menu.push_back("Exit");
  return Menu;
}

void UsersManager::FreeLoadedData() {
  for (auto pair : usersMap) {
    delete pair.second;
  }
  usersMap.clear();

  currentUser = nullptr;
}

UsersManager::~UsersManager() {

  FreeLoadedData();

  if (customersManager != nullptr) {
    delete customersManager;
    customersManager = nullptr;
  }

  if (adminsManager != nullptr) {
    delete adminsManager;
    adminsManager = nullptr;
  }
}
