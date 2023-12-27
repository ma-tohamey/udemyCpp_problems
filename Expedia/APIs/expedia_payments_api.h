#pragma once

#include "../Headers/json.hpp"

class PayPalCreditCard {
public:
  std::string name;
  std::string address;
  std::string id;
  std::string expiry_date;
  int ccv;
};

class PayPalOnlinePaymentAPI {
public:
  void SetCardInfo(const PayPalCreditCard *const card) {}
  bool MakePayment(double money) { return true; }
};

class StripeUserInfo {
public:
  std::string name;
  std::string address;
};

class StripeCardInfo {
public:
  std::string id;
  std::string expiry_date;
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
    // std::cout << JsonQuery << "\n";
    json::JSON obj = json::JSON::Load(JsonQuery);
    return true;
  }
};
