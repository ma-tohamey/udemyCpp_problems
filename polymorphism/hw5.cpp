#include <algorithm>
#include <iostream>
#include <vector>

class Object {
public:
  virtual std::string GetClassName() const = 0;
  virtual ~Object() {}
};

class Cloneable : virtual public Object {
public:
  virtual Object *Clone() const = 0;
  virtual ~Cloneable() {}
};
class Printerable : virtual public Object {
public:
  virtual void Print() const = 0;
  virtual ~Printerable() {}
};
class Comparable : virtual public Object {
public:
  virtual bool Compare(Comparable *) const = 0;
  virtual ~Comparable() {}
};
class Sortable : public Object {
public:
  virtual void Sort() = 0;
  virtual ~Sortable() {}
};

class Payable : public Cloneable, public Printerable, public Comparable {
public:
  virtual double getAmoutToPay() const = 0;
  virtual Payable *Clone() const = 0;
};

class Employee : public Payable {
public:
  double salary;
  std::string name;
  Employee(double salary, std::string name) : salary(salary), name(name) {}
  // Employee(std::string name, double salary) : name(name), salary(salary) {}

  virtual std::string GetClassName() const override { return "Employee"; };

  virtual double getAmoutToPay() const override { return salary; }

  virtual Employee *Clone() const override { return new Employee(*this); }

  virtual void Print() const override {
    std::cout << "Employee: " << name << " has Salary: " << salary << std::endl;
  }

  virtual bool Compare(Comparable *other) const override {
    Employee *otherEmp = dynamic_cast<Employee *>(other);
    if (otherEmp != nullptr &&
        std::tie(salary, name) < std::tie(otherEmp->salary, otherEmp->name))
      return true;
    else
      return false;
  }
};

class Invoice : public Payable {
public:
  double cost;

  Invoice(double cost) : cost(cost) {}
  virtual std::string GetClassName() const override { return "Invoice"; };

  virtual double getAmoutToPay() const override { return cost; }

  virtual Invoice *Clone() const override { return new Invoice(*this); }

  virtual void Print() const override {
    std::cout << "this is an Invoice and it's cost is: " << cost << std::endl;
  }

  virtual bool Compare(Comparable *other) const override {
    Invoice *otherInvoice = dynamic_cast<Invoice *>(other);
    if (otherInvoice != nullptr && otherInvoice->cost > cost)
      return true;
    else
      return false;
  }
};

bool Compare(Payable *obj1, Payable *obj2) {
  if (obj1->GetClassName() != obj2->GetClassName())
    return obj1->GetClassName() < obj2->GetClassName();

  return obj1->Compare(obj2);
}

class CompanyPayroll : public Printerable, public Sortable {
public:
  std::vector<Payable *> payables;

  void AddPayable(const Payable &payable) {
    payables.push_back(payable.Clone());
  }

  virtual std::string GetClassName() const override { return "CompanyPayroll"; }
  virtual void Print() const override {
    double totalCost = 0;
    for (auto &payable : payables) {
      payable->Print();
      totalCost += payable->getAmoutToPay();
    }
    std::cout << "Total to be Paid: $" << totalCost << std::endl;
  }
  virtual void Sort() override {
    std::sort(payables.begin(), payables.end(), Compare);
  }

  ~CompanyPayroll() {
    for (auto &payable : payables)
      delete payable;
    payables.clear();
  }
};

void test() {
  CompanyPayroll payroll;

  payroll.AddPayable(Employee(50, "mostafa"));
  payroll.AddPayable(Invoice(200));
  payroll.AddPayable(Employee(10, "ziad"));
  payroll.AddPayable(Invoice(100));
  payroll.AddPayable(Employee(30, "belal"));
  payroll.AddPayable(Invoice(300));

  payroll.Sort();
  payroll.Print(); // Notice ordered

  /*
Employee ziad has salary 10
Employee belal has salary 30
Employee mostafa has salary 50
Invoice cost 100
Invoice cost 200
Invoice cost 300
Total to be paid: 690
   */
}

int main() {
  test();

  return 0;
}
