#include "../Headers/Utilities.h"

int ToInt(std::string &userChoice) {
  int userChoiceNumber;
  std::istringstream iss(userChoice);

  if (!(iss >> userChoiceNumber))
    std::cout << "Error: ==>[ Invalid Input Type ]. Please enter a valid [ "
                 "Integer ].\n";

  return userChoiceNumber;
}

int GetUserChoice() {
  std::string userChoiceStr;
  int userChoice;

  std::cin >> userChoiceStr;
  userChoice = ToInt(userChoiceStr);
  return userChoice;
}
