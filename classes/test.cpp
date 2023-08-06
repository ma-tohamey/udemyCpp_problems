#include <iostream>
using namespace std;

class OurPrice {
private:
  int price;

public:
  OurPrice(int price) : price(price){};
  int GetPrice() {
    return this->price;
  } // which one is better = it is a matter of prefrances

  void SetPrice(int price) {
    if (price < 10)
      price = 0;
    this->price = price;
  }

  int someFun() {
    int price = 10;
    int price2 = 20;
    int price3 = 30;

    return price + price2 + price3;
  }
};

int main(int argc, char *argv[]) {
  OurPrice p1(5);

  cout << p1.GetPrice() << endl;

  return 0;
}
