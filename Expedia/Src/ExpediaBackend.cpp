#include "../Headers/ExpediaBackend.h"

ExpediaBackend::ExpediaBackend()
    : systemFrontend(new ExpediaFrontend),
      usersManager(new UsersManager(systemFrontend)) {}

void ExpediaBackend::run() {
  while (true) {
    usersManager->GetMenu(Menu);
    systemFrontend->PrintMenu(Menu);
    systemFrontend->PrintGetUserChoiceMessage(Menu.size());

    userChoice = GetUserChoice();
    if (!usersManager->HandelUserChoice(systemFrontend, userChoice))
      break;
  }
}

ExpediaBackend::~ExpediaBackend() {
  delete usersManager;
  usersManager = nullptr;
  delete systemFrontend;
  systemFrontend = nullptr;
}
