#include <iostream>
#include <ostream>

struct Vector2 {
  float x, y;

  Vector2(float x, float y) : x(x), y(y) {}

  Vector2 Add(const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);
  }

  Vector2 Multiply(const Vector2 &other) const {
    return Vector2(x * other.x, y * other.y);
  }

  Vector2 operator+(const Vector2 &other) const {
    // return Vector2(x + other.x, y + other.y);
    return Add(other);
  }

  Vector2 operator*(const Vector2 &other) const {
    // return Vector2(x * other.x, y * other.y);
    return Multiply(other);
  }

  bool operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const Vector2 &other) const { return !(*this == other); }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other) {
  stream << other.x << ' ' << other.y;
  return stream;
}

int main(int argc, char *argv[]) {
  Vector2 position(4.0f, 4.0f);
  Vector2 position1(4.0f, 4.0f);
  Vector2 speed(0.5f, 1.5f);
  Vector2 powerup(1.1f, 1.1f);

  // Vector2 result = position.Add(speed.Multiply(powerup));
  Vector2 result = position + speed * powerup;
  std::cout << result << std::endl;

  if (position == powerup)
    std::cout << "True" << std::endl;
  else
    std::cout << "False" << std::endl;

  if (position == position1)
    std::cout << "True" << std::endl;
  else
    std::cout << "False" << std::endl;

  std::cout << (position == powerup) << std::endl;
  std::cout << (position == position1) << std::endl;
  std::cin.get();
  return 0;
}
