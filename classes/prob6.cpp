#include <iostream>
#include <vector>
using namespace std;

class Time {
private:
  // Put on separate lines for code clarity
  int total_seconds;

public:
  Time(int hours, int minutes, int seconds) {
    SetTime(hours, minutes, seconds);
  }
  void SetTime(int hours, int minutes, int seconds) {
    total_seconds = 0;
    SetHours(hours);
    SetMinutes(minutes);
    SetSeconds(seconds);
  }
  int GetTotalSeconds() { return total_seconds; }
  int GetTotalMinutes() { return GetHours() * 60 + GetMinutes(); }
  void PrintHHMMSS() {
    cout << GetHours() << ':' << GetMinutes() << ':' << GetSeconds() << endl;
  }
  int GetHours() { return total_seconds / 3600; }
  void SetHours(int hours) {
    if (hours < 0)
      hours = 0;
    this->total_seconds += (GetHours() - hours) * 3600;
  }
  int GetMinutes() { return (total_seconds - (GetHours() * 3600)) / 60; }
  void SetMinutes(int minutes) {
    if (minutes < 0)
      minutes = 0;
    this->total_seconds += (GetMinutes() - minutes) * 60;
  }
  int GetSeconds() { return total_seconds % 60; }
  void SetSeconds(int seconds) {
    if (seconds < 0)
      seconds = 0;
    this->total_seconds += seconds - GetSeconds();
  }
};

int main() {
  Time t(0, 0, 0);
  t.SetMinutes(1);
  t.SetSeconds(60);
  t.SetHours(2);
  cout << t.GetTotalSeconds() << endl;
  t.PrintHHMMSS();
  return 0;
}
