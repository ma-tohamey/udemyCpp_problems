#include <cstring>
#include <iostream>

class String {
private:
  char *m_Buffer;
  unsigned int m_Size;

public:
  String(const char *string) {
    m_Size = strlen(string);
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string, m_Size + 1);
    m_Buffer[m_Size] = 0;
  }
  String(const String &other) : m_Size(other.m_Size) {
    std::cout << "copied object!" << std::endl;
    m_Buffer = new char[m_Size];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
  }
  ~String() { delete[] m_Buffer; }
  friend std::ostream &operator<<(std::ostream &stream, const String &string);

  char &operator[](unsigned int index) { return m_Buffer[index]; }
};

std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.m_Buffer;
  return stream;
}

int main(int argc, char *argv[]) {
  String name("The cherno");
  String second = name;

  std::cout << name << std::endl;
  std::cout << name[4] << std::endl << std::endl;

  second[4] = 'b';
  std::cout << second << std::endl;
  std::cout << second[4] << std::endl << std::endl;
  return 0;
}
