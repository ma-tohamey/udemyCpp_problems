#include <cstring>
#include <iostream>
#include <string>

class String {
private:
  char *m_Buffer;
  unsigned int m_Size;

public:
  String(const char *string) {
    m_Size = strlen(string);
    m_Buffer = new char[m_Size];
    // for (int i = 0; i < m_Size; ++i)
    //   m_Buffer[i] = string[i];
    memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size] = 0;
  }

  // String(const String &other)
  //     : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}
  String(const String &origin) : m_Size(origin.m_Size) {
    // std::cout << "copied string! " << std::endl;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, origin.m_Buffer, m_Size + 1);
  }

  ~String() { delete[] m_Buffer; }

  char &operator[](unsigned int index) { return m_Buffer[index]; }
  friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.m_Buffer;
  return stream;
}
int main(int argc, char *argv[]) {
  String string = "Cherno";
  String second = string;

  second[2] = 'a';
  std::cout << string << std::endl;
  std::cout << second << std::endl;
  return 0;
}
