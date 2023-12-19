#include <iostream>
using namespace std;
class Parent {
public:
  virtual void print() { cout << "I'm the parent class\n"; }
  void base() { cout << " It is the function of the Parent class " << endl; }
};

class Child : public Parent {
public:
  void print() { cout << "I'm the child class\n"; }
  void derive() { cout << " it is the function of the Child class " << endl; }
};

int main() {
  // upcasting using refrence
  //
  // Child child;
  // Parent &parentIntoChild = child;
  // parentIntoChild.base();
  //

  // upcasting using pointers
  // Child child;
  // Parent *parentPtr = &child;
  // parentPtr->base();
  //
  //
  // downcasting using refrence
  // Parent parent;
  // Child &child = (Child &)parent;
  // child.print();
  //
  // downcasting using pointers
  // Parent parent;
  // Child *childptr = (Child *)&parent;
  return 0;
}
