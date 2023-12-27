#include "../Headers/ExpediaFrontend.h"

void ExpediaFrontend::PrintMenu(std::vector<std::string> &Menu) {
  std::cout << "\nMenu: \n";

  for (int i = 0; i < Menu.size(); ++i)
    std::cout << "\n\t" << i + 1 << ": " << Menu[i];
}

void ExpediaFrontend::PrintWelcomingMessage(const std::string &user_name,
                                            const std::string &user_Type) {
  std::cout << "Hello " << user_name << " | " << user_Type << " View\n";
}

void ExpediaFrontend::PrintLogoutMessage(const std::string &user_name) {
  std::cout << "\t===> " << user_name << " has logged out\n";
}
void ExpediaFrontend::PrintExitingMessage() {
  std::cout << "\n\t-----------------------------------------";
  std::cout << "\n\t| ==> Terminating the program safly. :) |\n";
  std::cout << "\t-----------------------------------------\n";
}

void ExpediaFrontend::PrintGetUserChoiceMessage(int choicesCeil,
                                                bool isCancable) {
  std::cout << "\nEnter ";
  if (isCancable)
    std::cout << "-1 to cancel or ";

  std::cout << "number in range 1 - " << choicesCeil << ": ";
}

void ExpediaFrontend::PrintInvalidUserChoiceMessage() {
  std::cout << "Error: ==>[ Not Valid Choice ]. Please Try Again.\n";
}

ExpediaFrontend::~ExpediaFrontend() {}
