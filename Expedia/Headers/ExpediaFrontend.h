#pragma once
#include <iostream>
#include <vector>

class ExpediaFrontend {
public:
  ExpediaFrontend() {}

  void PrintMenu(std::vector<std::string> &Menu);
  void PrintWelcomingMessage(const std::string &userName,
                             const std::string &userType);
  void PrintLogoutMessage(const std::string &userName);
  void PrintExitingMessage();
  void PrintGetUserChoiceMessage(int choicesCeil, bool isCancable = false);
  void PrintInvalidUserChoiceMessage();

  ~ExpediaFrontend();
};
