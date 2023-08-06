#include <cstring>
#include <iostream>

class String {
private:
  char *m_Buffer;
  int m_size;

public:
  String(const char *string) {
    m_size = strlen(string);
    m_Buffer = new char[m_size + 1];
    memcpy(m_Buffer, string, m_size + 1);
    m_Buffer[m_size] = 0;
  }

  String(const String &orgin) : m_size(orgin.m_size) {
    m_Buffer = new char[m_size];
    memcpy(m_Buffer, &orgin.m_Buffer, m_size);
  }

  ~String() { delete[] m_Buffer; }
};
