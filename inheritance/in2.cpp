// C++ program to demonstrate the working of public inheritance

#include <iostream>
using namespace std;

class Base {
private:
  int pvt = 1;

protected:
  int prot = 2;

public:
  int pub = 3;

  // function to access private member
  int getPVT() { return pvt; }
};

class PrivateDerived : private Base {
public:
  // function to access protected member from Base
  int getProt() { return prot; }

  int getPub() { return pub; }
};

int main() {

  // PublicDerived object1;
  // // Error: member "Base::pvt" is inaccessible
  // // cout << "Private = " << object1.pvt;
  //
  // // Error: member "Base::prot" is inaccessible
  // // cout << "Protected = " << object1.prot;
  // cout << "Private = " << object1.getPVT() << endl;
  // cout << "Protected = " << object1.getProt() << endl;
  // cout << "Public = " << object1.pub << endl;

  // ProtectedDerived object1;
  // // can't access the private section in protected specifire
  // // cout << "Private = " << object1.getPVT() << endl;
  //
  // cout << "Protected = " << object1.getProt() << endl;
  //
  // // can't just access the pub because it became in the protecte specifire
  // // cout << "Public = " << object1.pub << endl;
  // cout << "Public = " << object1.getPub() << endl;

  // PrivateDerived object1;
  // cout << "Protected = " << object1.getProt() << endl;
  // cout << "Public = " << object1.getPub() << endl;
  return 0;
}
