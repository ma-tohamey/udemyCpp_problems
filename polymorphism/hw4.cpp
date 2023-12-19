#include "json.hpp"
#include <iostream>
#include <string>
#include <strstream>
#include <vector>
using namespace std;

// PayPalCreditCard and PayPalOnlinePaymentAPI are NOT our code. They are Paypal
// API. We have to use them to be able to call PayPal service

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

class SquarePayment : public IPayment {
private:
  std::string name;
  std::string address;
  std::string id;
  std::string expire_date;
  int ccv;
  SquarePaymentAPI *squaPaymentAPI = new SquarePaymentAPI;

public:
  virtual void SetName(std::string name) { this->name = name; }
  virtual void SetAddress(std::string address) { this->address = address; };
  virtual void SetId(std::string id) { this->id = id; }
  virtual void SetExpireDate(std::string expire_date) {
    this->expire_date = expire_date;
  }
  virtual void SetCCV(int ccv) { this->ccv = ccv; }

  virtual bool MakePayment(double requriedMoney) {
    json::JSON obj;
    obj["card_info"]["CCV"] = ccv;
    obj["card_info"]["DATE"] = expire_date;
    obj["card_info"]["ID"] = id;
    obj["money"] = requriedMoney;
    obj["user_info"] = json::Array(name, address);

    ostrstream oss;
    oss << obj;
    std::string JsonQuery = oss.str();

    return squaPaymentAPI->WithDrawMoney(JsonQuery);
  }
};

class PaypalPayment : public IPayment {
private:
  PayPalCreditCard *paypallCard = new PayPalCreditCard;
  PayPalOnlinePaymentAPI *paypalPaymentAPI = new PayPalOnlinePaymentAPI;

public:
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

class StripePayment : public IPayment {
private:
  StripeUserInfo *stripeUserInfo = new StripeUserInfo;
  StripeCardInfo *stripeCardInfo = new StripeCardInfo;
  StripePaymentAPI *stripePaymentAPI = new StripePaymentAPI;

public:
  virtual void SetName(std::string name) override {
    stripeUserInfo->name = name;
  }
  virtual void SetAddress(std::string address) override {
    stripeUserInfo->address = address;
  }
  virtual void SetId(std::string id) override { stripeCardInfo->id = id; };
  virtual void SetExpireDate(std::string expire_date) override {
    stripeCardInfo->expire_date = expire_date;
  }
  virtual void SetCCV(int ccv) override {
    // there's no impelementaion for this function in stripe api's
  }

  virtual bool MakePayment(double requriedMoney) override {
    return StripePaymentAPI::WithDrawMoney(*stripeUserInfo, *stripeCardInfo,
                                           requriedMoney);
  }

  virtual ~StripePayment() {
    delete stripeUserInfo;
    delete stripeCardInfo;
    delete stripePaymentAPI;
  }
};

class PaymentManager {
public:
  static IPayment *GetPaymentMethod() {
    std::string paymentName;
    if (paymentName == "PaypalPayment")
      return new PaypalPayment;
    else
      return new StripePayment;
  }
};

class Craigslist {
private:
  IPayment *payment;

public:
  Craigslist() {}
  bool Pay(TransactionInfo info) {
    // /* TODO */: generic (no nothing about Paypal)
    info.GetTransactionData();

    payment = PaymentManager::GetPaymentMethod();

    payment->SetName(info.name);
    payment->SetAddress(info.address);
    payment->SetExpireDate(info.expire_date);
    payment->SetId(info.id);
    payment->SetCCV(info.ccv);
    if (payment->MakePayment(info.required_money_amount))
      return true;
    else
      return false;

    delete payment;
  }
};

int main() {
  TransactionInfo info = {20.5,          "mostafa", "canada",
                          "11-22-33-44", "09-2021", 333};
  Craigslist site;
  if (site.Pay(info))
    std::cout << "payment done successfly" << std::endl;
  else
    std::cout << "paymnet faild" << std::endl;
  return 0;
}
