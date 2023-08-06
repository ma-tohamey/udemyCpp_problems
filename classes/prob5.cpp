#include <exception>
#include <iostream>
#include <vector>
using namespace std;

class Time {
private:
  // Put on separate lines for code clarity
  int hours;
  int minutes;
  int seconds;

public:
  Time(int hours, int minutes, int seconds)
      : hours(hours), minutes(minutes), seconds(seconds) {
    // There is member function doing the same task
    // Avoid code duplication
    SetTime(hours, minutes, seconds);
  }

  void SetTime(int hours, int minutes, int seconds) {
    // Put on separate lines for code clarity
    // Still there is a missing point her.
    // We better use setters as they validate/change input
    //
    SetHours(this->hours);
    SetMinutes(this->minutes);
    SetSeconds(this->seconds);
  }

  int GetTotalSeconds() { return hours * 60 * 60 + minutes * 60 + seconds; }
  int GetTotalMinutes() { return hours * 60 + minutes; }
  int GetHours() { return hours; }
  int GetMinutes() { return minutes; }
  int GetSeconds() { return seconds; }

  void PrintHHMMSS() {
    cout << hours << ':' << minutes << ':' << seconds << endl;
  }

  int excced60(int &value, char min_sec) {
    if (min_sec == 'm')
      hours += (value / 60);
    else
      minutes += (value / 60);
    return value % 60;
  };

  Time &SetHours(int hours) {
    // Be careful from missing verifications. This is important for
    // "data-integrity"
    if (hours < 0)
      hours = 0;
    this->hours = hours;

    return *this;
  }

  Time &SetMinutes(int minutes) {
    if (minutes < 0)
      minutes = 0;
    else if (minutes >= 60)
      this->minutes = excced60(minutes, 'm');
    else
      this->minutes = minutes;

    return *this;
  }

  Time &SetSeconds(int seconds) {
    if (seconds < 0)
      seconds = 0;
    else if (seconds >= 60)
      this->seconds = excced60(seconds, 's');
    else
      this->seconds = seconds;

    return *this;
  }
};

int main() {
  // This will print wrongly. E.g. every 60 second should be added as a minute.
  // Every 60 minutes should be added as an hour
  // Time t(0, 120, 120);
  // t.PrintHHMMSS(); // proper printing: 2:2:0
  //
  Time t(0, 100, 100);
  t.PrintHHMMSS(); // proper printing: 2:2:0

  t.SetHours(5).SetMinutes(45).SetSeconds(13);
  t.PrintHHMMSS();

  return 0;
}
