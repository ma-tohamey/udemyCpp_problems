#include <iostream>

int main(int argc, char *argv[]) {

  std::string cnt_password, user_password;
  user_password = "snackbox979";
  bool first_time = true;

  do {
    if (first_time)
      std::cout << "Enter your password: ", first_time = false;
    else
      std::cout << "Wrong password please Try again: ";
    std::cin >> cnt_password;
  } while (cnt_password != user_password);
  return 0;
}
