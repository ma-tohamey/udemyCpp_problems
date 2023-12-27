#pragma once

class Reservation {
public:
  virtual void Read() = 0;
  virtual void Print() = 0;
  virtual double GetTotalPrice() = 0;
  virtual ~Reservation();
};
