#pragma once
#include "./User.h"

class Customer : public User {
private:
public:
  Customer();

  virtual bool SetUserType() override;
  virtual void Read(const std::string &userName) override;

  virtual void ViewProfile() const override;

  void MakeItinerarty();
  void ListMyItineraries();

  virtual ~Customer() override;
};
