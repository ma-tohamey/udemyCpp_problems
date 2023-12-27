#include "../Headers/FlightInfo.h"

void FlightInfo::Print() const {
  std::cout << "Airline: " << airLineName << " Cost: " << cost
            << " Departure Date " << dateTimeFrom << " Arrival date "
            << dateTimeTo << std::endl;
}

const std::string &FlightInfo::GetAirlineName() const { return airLineName; }
const std::string &FlightInfo::GetDateTimeFrom() const { return dateTimeFrom; }
const std::string &FlightInfo::GetDateTimeTo() const { return dateTimeFrom; }
const std::string &FlightInfo::GetFromCity() const { return fromCity; }
const std::string &FlightInfo::GetToCity() const { return toCity; }
const int FlightInfo::GetAdultsNum() const { return adulstNum; }
const int FlightInfo::GetChildreNum() const { return childrenNum; }
const int FlightInfo::GetInfantsNum() const { return infantsNum; }
double FlightInfo::GetCost() const { return cost; }

void FlightInfo::SetDateTimeFrom(const std::string &dateTimeFrom) {
  this->dateTimeFrom = dateTimeFrom;
}
void FlightInfo::SetDateTimeTo(const std::string &dateTimeTo) {
  this->dateTimeTo = dateTimeTo;
}
void FlightInfo::SetCost(double cost) { this->cost = cost; }
void FlightInfo::SetAirlineName(const std::string &airLineName) {
  this->airLineName = airLineName;
}
