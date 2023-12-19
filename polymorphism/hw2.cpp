// #include <iostream>
#include <vector>

class Reservation {
public:
  // abstarct reservation class
  virtual double GetTotalCost() const = 0;
  virtual Reservation *Clone() = 0;
  virtual ~Reservation();
};

class FlightReservation : public Reservation {
public:
  FlightReservation() {}
  // some flight info
  virtual double GetTotalCost() const override { return 2000; }
  virtual FlightReservation *Clone() override {
    return new FlightReservation();
  }
};

class HotelReservation : public Reservation {
private:
  double pricePerNight;
  int totalNights;

public:
  HotelReservation(double pricePerNight, int totalNights)
      : pricePerNight(pricePerNight), totalNights(totalNights) {}
  virtual double GetTotalCost() const override {
    return pricePerNight * totalNights;
  }

  virtual HotelReservation *Clone() override {
    return new HotelReservation(*this);
  }
};

class Itinerary {
private:
  std::vector<Reservation *> reservations;

public:
  void AddReservation(Reservation *reservation) {
    reservations.push_back(reservation->Clone());
  }

  virtual double GetTotalCost() {
    double totalCost = 0;
    for (auto reservation : reservations)
      totalCost += reservation->GetTotalCost();
    return totalCost;
  }

  void Clear() {
    for (auto *reservation : reservations)
      delete reservation;
    reservations.clear();
  }
};

int main(int argc, char *argv[]) {
  // some code
  return 0;
}
