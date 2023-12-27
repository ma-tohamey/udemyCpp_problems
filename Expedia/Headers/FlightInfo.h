#include <iostream>

class FlightInfo {
private:
  double cost;
  std::string airLineName;
  std::string dateTimeFrom;
  std::string dateTimeTo;

  std::string fromCity;
  std::string toCity;

  int adulstNum;
  int childrenNum;
  int infantsNum;

public:
  void Print() const;

  const std::string &GetAirlineName() const;
  const std::string &GetDateTimeFrom() const;
  const std::string &GetDateTimeTo() const;
  const std::string &GetFromCity() const;
  const std::string &GetToCity() const;
  const int GetAdultsNum() const;
  const int GetChildreNum() const;
  const int GetInfantsNum() const;
  double GetCost() const;

  void SetDateTimeFrom(const std::string &dateTimeFrom);
  void SetDateTimeTo(const std::string &dateTimeTo);
  void SetCost(double cost);
  void SetAirlineName(const std::string &airLineName);
  void SetFromCity(const std::string fromCity);
  void SetToCity(const std::string toCity);
  void SetAdultsNum(int adultsNum);
  void SetChildrenNum(int childrenNum);
  void SetInfantsNum(int infantsNum);
};
