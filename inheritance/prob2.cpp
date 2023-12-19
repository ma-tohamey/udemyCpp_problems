#include <iostream>
#include <vector>

class Address {
private:
  std::string name;
  std::string address;
  std::string city;

public:
  Address() {}

  void setName(std::string name) { this->name = name; }
  void setAddress(std::string address) { this->address = address; }
  void setCity(std::string city) { this->city = city; }

  const std::string &getName() const { return name; }
  const std::string &getAddress() const { return address; }
  const std::string &getCity() const { return city; }
};

class StandardPackage {
private:
  Address senderAddress;
  Address reciverAddress;
  double weight_KG;
  double price_KG;

public:
  StandardPackage(const Address senderAddress, const Address reciverAddress,
                  double weight_KG, double price_KG)
      : senderAddress(senderAddress), reciverAddress(reciverAddress),
        weight_KG(weight_KG), price_KG(price_KG) {}

  // setters
  void setSenderAddress(Address senderAddress) {
    this->senderAddress = senderAddress;
  }
  void setReciverAddress(Address reciverAddress) {
    this->reciverAddress = reciverAddress;
  }
  void setWeight(double weight_KG) { this->weight_KG = weight_KG; }
  void setPriceKG(double price_KG) { this->price_KG = price_KG; }

  // getters
  const Address &getSenderAddress() const { return senderAddress; }
  const Address &getReciverAddress() const { return reciverAddress; }
  const double getWeight_KG() const { return weight_KG; }
  const double getPrice_KG() const { return price_KG; }
  const double getTotalCost() const { return weight_KG * price_KG; }
};

class TwoDaysPackage : public StandardPackage {
private:
  double fixedFee;

public:
  TwoDaysPackage(const Address senderAddress, const Address reciverAddress,
                 double weight_KG, double price_KG)
      : StandardPackage(senderAddress, reciverAddress, weight_KG, price_KG) {}

  // setters
  void setFixedFee(double fixedFee) { this->fixedFee = fixedFee; }

  // getters
  double getFixedFee() const { return fixedFee; }
  double getTotalCost() const {
    return StandardPackage::getTotalCost() + fixedFee;
  }
};

class HeavyPackage : public StandardPackage {
private:
  const double WEIGHT_LIMIT = 100.00;
  double extraFee_KG;

public:
  HeavyPackage(const Address senderAddress, const Address reciverAddress,
               double weight_KG, double price_KG)
      : StandardPackage(senderAddress, reciverAddress, weight_KG, price_KG) {}

  // setters
  void setExtraFee_KG(double extraFee_KG) { this->extraFee_KG = extraFee_KG; }

  // getters
  const double getExtraFee() { return extraFee_KG; }
  const double getTotalCost() {
    double totalCost = StandardPackage::getTotalCost();
    if (getWeight_KG() > WEIGHT_LIMIT)
      totalCost += ((getWeight_KG() - WEIGHT_LIMIT) * extraFee_KG);

    return totalCost;
  }
};

class PaymentCard {
private:
  std::string card_number;
  double expiry_date;
};

class CreditCard : public PaymentCard {};

class DebitCard : public PaymentCard {};

class Shipment {
private:
public:
};

class Customer {
private:
  std::vector<Shipment> shipments;
  std::vector<CreditCard> credit_cards;
  std::vector<DebitCard> debit_cards;

public:
  void AddShipment() {}
};
