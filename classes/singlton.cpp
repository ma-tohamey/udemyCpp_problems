#include <iostream>

class Random {
private:
  std::string path;
  Random() {}
  Random(Random &) = delete;
  // static Random s_instance;
  Random &operator=(const Random &) = delete;

  float m_RandomGenerator = 0.5f;
  float IFloat() { return m_RandomGenerator; }

public:
  static Random &Get() {
    static Random instance;
    return instance;
  }

  static float Float() { return Get().IFloat(); }
};

// Random Random::s_instance;

int main(int argc, char *argv[]) {
  // Random &random = Random::Get();
  // float f_number = random.Float();
  float f_number = Random::Float();
  std::cout << f_number << std::endl;
  return 0;
}
