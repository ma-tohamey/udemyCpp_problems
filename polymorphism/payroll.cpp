#include <iostream>
#include <vector>

class Paypall {
public:
  virtual double getAmoutToPay() const = 0;
  virtual ~Paypall() {}
};

class Person : public Paypall {
private:
  std::string name;
  std::string address;

public:
  // some getters and setters
  virtual ~Person() {}
};
class Volunteers : public Person {
private:
  int payment;

public:
  virtual double getAmoutToPay() { return payment; }
};

class Employee : public Paypall {
private:
  // soem info about the every employee

public:
};

class hourlyEmployee : public Employee {
private:
  int workedHours;
  int salaryPerHour;

public:
  virtual double getAmoutToPay() { return workedHours * salaryPerHour; }
};

class salariedEmployee : public Employee {
protected:
  double salary;

public:
  virtual double getAmoutToPay() { return salary; }
};

class CommisionEmployee : public salariedEmployee {
private:
  int soldPieces;
  double commisionPerUnite;

public:
  virtual double getAmoutToPay() {
    return salary + commisionPerUnite * soldPieces;
  }
};

class Item { // abstact class of an item
public:
  virtual double getPrice() = 0;
  virtual ~Item() {}
};

class book : public Item {
  // some book info
};

class food : public Item {
  // some food info
};

class Invoice {
private:
  std::vector<Item *> items;

public:
  void addItem(Item *item) { items.push_back(item); }

  virtual double getAmoutToPay() {
    double total = 0;
    for (auto item : items)
      total += item->getPrice();
    return total;
  }
};

class Payroll {
private:
  std::vector<Paypall *> paypalls;

public:
  void AddPaypall(Paypall *paypall) { paypalls.push_back(paypall); }
};
// int main() { std::cout << "hello world"; }
