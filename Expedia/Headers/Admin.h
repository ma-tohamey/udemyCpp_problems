#pragma once
#include "./User.h"

class Admin : public User {
private:
public:
  Admin();

  virtual bool SetUserType() override;
  virtual void Read(const std::string &userName) override;
  virtual void ViewProfile() const override;

  virtual ~Admin() override;
};
