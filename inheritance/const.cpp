// const int number;
class Base {
public:
  Base() {
    // Constructor body for Base class (if needed)
  }

protected:
  int id;
  // const int MAXNumber;
};

class Derived : public Base {
public:
  Derived(int d_id) : d_id(d_id) {
    // Constructor body for Derived class (if needed)
    int number = 10 + id;
  }

private:
  int d_id;
};

int main(int argc, char *argv[]) {
  // some code
  Derived derived(10);
  return 0;
}
