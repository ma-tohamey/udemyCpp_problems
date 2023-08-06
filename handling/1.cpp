#include <exception>
#include <iostream>
#include <stdexcept>

struct BankAccount {
  int money = 1000;
  bool paybill(int bill_value) {
    if (bill_value < 0)
      throw std::invalid_argument("Bill value can't be negative!");
    if (money >= bill_value) {
      money -= bill_value;
      return true;
    } else
      return false;
  }
};

int main(int argc, char *argv[]) {
  BankAccount acct;
  try {
    std::cout << acct.paybill(100) << std::endl;
    std::cout << acct.paybill(500000) << std::endl;
    std::cout << acct.paybill(-10) << std::endl;
    std::cout << acct.paybill(200) << std::endl;
  } catch (std::invalid_argument &erorr) {
    std::cout << "Caught an exception: " << erorr.what() << std::endl;
    throw erorr;
  }
  std::cout << "bye" << std::endl;
  return 0;
}
