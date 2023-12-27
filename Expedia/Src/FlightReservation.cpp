#include "../Headers/FlightReservation.h"
#include <iostream>

string ToString() const {
  ostringstream oss;
  oss << "Airline: " << airline_name << " Cost: " << total_cost
      << " Departure Date " << date_time_from << " Arrival date "
      << date_time_to;
  return oss.str();
}

const string &GetDateTimeFrom() const { return date_time_from; }

void SetDateTimeFrom(const string &dateTimeFrom) {
  date_time_from = dateTimeFrom;
}

const string &GetDateTimeTo() const { return date_time_to; }

void SetDateTimeTo(const string &dateTimeTo) { date_time_to = dateTimeTo; }

double GetTotalCost() const { return total_cost; }

void SetTotalCost(double totalCost) { total_cost = totalCost; }

const string &GetAirlineName() const { return airline_name; }

void SetAirlineName(const string &airlineName) { airline_name = airlineName; }
