#include <iostream>
#include <vector>
using namespace std;

class Address {
private:
  string name;
  string address;
  string city;

public:
  Address(std::string name, std::string address, std::string city)
      : name(name), address(address), city(city) {}
  const string &GetAddress() const { return address; }

  void SetAddress(const string &address) { this->address = address; }

  const string &GetCity() const { return city; }

  void SetCity(const string &city) { this->city = city; }

  const string &GetName() const { return name; }

  void SetName(const string &name) { this->name = name; }
};

class StandardPackage {
private:
  Address sender_address;
  Address reciever_address;
  double weight_kg;
  double price_per_kg;

public:
  StandardPackage(const Address &sender_address,
                  const Address &reciever_address, double weight_kg,
                  double price_per_kg)
      : sender_address(sender_address), reciever_address(reciever_address),
        weight_kg(weight_kg), price_per_kg(price_per_kg) {}

  virtual double TotalCost() const { return weight_kg * price_per_kg; }

  double GetPricePerKg() const { return price_per_kg; }

  void SetPricePerKg(double pricePerKg) { price_per_kg = pricePerKg; }

  const Address &GetRecieverAddress() const { return reciever_address; }

  void SetRecieverAddress(const Address &recieverAddress) {
    reciever_address = recieverAddress;
  }

  const Address &GetSenderAddress() const { return sender_address; }

  void SetSenderAddress(const Address &senderAddress) {
    sender_address = senderAddress;
  }

  double GetWeightKg() const { return weight_kg; }

  void SetWeightKg(double weightKg) { weight_kg = weightKg; }
};

class TwoDayPackage : public StandardPackage {
private:
  double fixed_fee;

public:
  TwoDayPackage(const Address &sender_address, const Address &reciever_address,
                double weight_kg, double price_per_kg, double fixed_fee)
      : StandardPackage(sender_address, reciever_address, weight_kg,
                        price_per_kg),
        fixed_fee(fixed_fee) {}

  double TotalCost() const { return StandardPackage::TotalCost() + fixed_fee; }

  double GetFixedFee() const { return fixed_fee; }

  void SetFixedFee(double fixedFee) { fixed_fee = fixedFee; }
};

class HeavyPackage : public StandardPackage {
private:
  const double limit_kg = 100;
  double extra_price_per_kg;

public:
  HeavyPackage(const Address &sender_address, const Address &reciever_address,
               double weight_kg, double price_per_kg, double extra_price_per_kg)
      : StandardPackage(sender_address, reciever_address, weight_kg,
                        price_per_kg),
        extra_price_per_kg(extra_price_per_kg) {}

  double TotalCost() const {
    double ret = StandardPackage::TotalCost();

    if (GetWeightKg() > limit_kg)
      ret += (GetWeightKg() - limit_kg) * extra_price_per_kg;
    return ret;
  }

  double GetExtraPricePerKg() const { return extra_price_per_kg; }

  void SetExtraPricePerKg(double extraPricePerKg) {
    extra_price_per_kg = extraPricePerKg;
  }
};

class PaymentCard {
private:
  string card_number;
  double expiry_date;
};

class CreditCard : public PaymentCard {};

class DebitCard : public PaymentCard {};

class Shipment {
private:
  vector<StandardPackage const *> standard_packages;
  // How ugly is such way below?!
  // vector<StandardPackage> standard_packages;
  // vector<TwoDayPackage> two_day_packages;
  // vector<HeavyPackage> heavy_packages;

  CreditCard credit_card;
  DebitCard debit_card;
  bool is_credit_card_used;

public:
  void AddPackage(const StandardPackage *package) {
    standard_packages.push_back(package);
  }
  // void AddStandardPackage(const StandardPackage &package) {
  //   standard_packages.push_back(package);
  // }
  // void AddTwoDayPackage(const TwoDayPackage &package) {
  //   two_day_packages.push_back(package);
  // }
  // void AddHeavyPackage(const HeavyPackage &package) {
  //   heavy_packages.push_back(package);
  // }

  void SetCreditCard(const CreditCard &credit_card_) {
    credit_card = credit_card_;
    is_credit_card_used = true;
  }
  void SetDebitCard(const DebitCard &debit_card_) {
    debit_card = debit_card_;
    is_credit_card_used = false;
  }

  double TotalCost() const {
    double total = 0;

    for (auto package : standard_packages)
      total += package->TotalCost();
    // What is wrong from OO principles here?
    // for (auto const &package : standard_packages)
    //   total += package.TotalCost();
    //
    // for (auto const &package : two_day_packages)
    //   total += package.TotalCost();
    //
    // for (auto const &package : heavy_packages)
    //   total += package.TotalCost();

    return total;
  }
};

class Customer {
private:
  vector<Shipment> shipments;
  vector<CreditCard> credit_cards;
  vector<DebitCard> debit_cards;

public:
  void AddShipment() {}
};

int main() {
  Address sender("mahmoud", "el-kishla", "Desouq");
  Address reciver("Abo Sanad", "Khobar", "Saudi Aribia");

  Shipment firstShip;
  StandardPackage sp1(sender, reciver, 70, 13.74);
  firstShip.AddPackage(&sp1);
  StandardPackage sp2(sender, reciver, 37, 13.74);
  firstShip.AddPackage(&sp2);
  StandardPackage sp3(sender, reciver, 92, 13.74);
  firstShip.AddPackage(&sp3);

  std::cout << firstShip.TotalCost() << std::endl;

  TwoDayPackage tdp1(sender, reciver, 13, 17.25, 25);
  firstShip.AddPackage(&tdp1);
  TwoDayPackage tdp2(sender, reciver, 9, 17.25, 25);
  firstShip.AddPackage(&tdp2);
  TwoDayPackage tdp3(sender, reciver, 2.78, 17.25, 25);
  firstShip.AddPackage(&tdp3);

  std::cout << firstShip.TotalCost() << std::endl;

  HeavyPackage hp1(sender, reciver, 13, 17.25, 25);
  firstShip.AddPackage(&tdp1);
  HeavyPackage hp2(sender, reciver, 9, 17.25, 25);
  firstShip.AddPackage(&tdp2);
  HeavyPackage hp3(sender, reciver, 2.78, 17.25, 25);
  firstShip.AddPackage(&tdp3);

  std::cout << firstShip.TotalCost() << std::endl;
  return 0;
}
