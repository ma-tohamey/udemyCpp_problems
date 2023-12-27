
#include "json.hpp"
#include <iostream>
#include <string>

using namespace std;

class PayPalCreditCard {
public:
  string name;
  string address;
  string id;
  string expire_date;
  int ccv;
};

class PayPalOnlinePaymentAPI {
public:
  void SetCardInfo(const PayPalCreditCard *const card) {}
  bool MakePayment(double money) { return true; }
};

class StripeUserInfo {
public:
  string name;
  string address;
};

class StripeCardInfo {
public:
  string id;
  string expire_date;
};

class StripePaymentAPI {
public:
  bool static WithDrawMoney(StripeUserInfo user, StripeCardInfo card,
                            double money) {
    return true;
  }
};

class SquarePaymentAPI {
public:
  bool static WithDrawMoney(std::string JsonQuery) {
    json::JSON obj = json::JSON::Load(JsonQuery);
    std::cout << obj << std::endl;
    return true;
  }
};

class TransactionInfo {
public:
  double required_money_amount;
  string name;
  string address;
  string id;
  string expire_date;
  int ccv;

  void PrintWelcome() {
    std::cout << "\t\t______________________________Hello "
                 "Sir.______________________________\n";
    std::cout << "__________Please Enter Your Credit Card Data To Complete "
                 "Your Purchasement.__________\n";
  }
  void SetName() {
    std::cout << "Enter Your Name: ";
    std::cin.ignore();
    std::getline(cin, name);
  }
  void SetAddress() {
    std::cout << "Enter Your Address: ";
    std::cin >> address;
  }
  void SetId() {
    std::cout << "Enter Your Credit Card ID: ";
    std::cin >> id;
  }
  void SetExpireDate() {
    std::cout << "Enter Your Credit Card Expire Date: ";
    std::cin >> expire_date;
  }
  void SetCCV() {
    std::cout << "Enter Your Credit Card CCV Number (If Exsist). :";
    std::cin >> ccv;
  }

  void GetTransactionData() {
    PrintWelcome();
    SetName();
    SetAddress();
    SetId();
    SetExpireDate();
    SetCCV();
  }
};

class IPayment {
public:
  virtual void SetName(std::string name) = 0;
  virtual void SetAddress(std::string address) = 0;
  virtual void SetId(std::string id) = 0;
  virtual void SetExpireDate(std::string expire_date) = 0;
  virtual void SetCCV(int ccv) = 0;

  virtual bool MakePayment(double requriedMoney) = 0;
  virtual ~IPayment() {}
};

class PaypalPayment : public IPayment {
public:
  PayPalCreditCard *paypallCard = new PayPalCreditCard;
  PayPalOnlinePaymentAPI *paypalPaymentAPI = new PayPalOnlinePaymentAPI;

  virtual void SetName(std::string name) override { paypallCard->name = name; }
  virtual void SetAddress(std::string address) override {
    paypallCard->address = address;
  }
  virtual void SetId(std::string id) override { paypallCard->id = id; };
  virtual void SetExpireDate(std::string expire_date) override {
    paypallCard->expire_date = expire_date;
  }
  virtual void SetCCV(int ccv) override { paypallCard->ccv = ccv; }

  virtual bool MakePayment(double requriedMoney) override {
    paypalPaymentAPI->SetCardInfo(paypallCard);
    return paypalPaymentAPI->MakePayment(requriedMoney);
  }

  virtual ~PaypalPayment() {
    delete paypallCard;
    delete paypalPaymentAPI;
  }
};
