#include <iostream>

class SidesColor {
private:
  std::string side1;
  std::string side2;
  std::string side3;
  std::string side4;
  std::string one_color;

public:
  SidesColor(){};

  // setters
  void SetSidesColor(std::string side1, std::string side2, std::string side3,
                     std::string side4) {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
    this->side4 = side4;
  }

  void SetOneColor(std::string color) { this->one_color = color; };

  // getters
  std::string GetSidesColor() {
    if (one_color == "")
      return this->side1 + ' ' + this->side2 + ' ' + this->side3 + ' ' +
             this->side4;

    return one_color;
  }
};

class Room {
private:
  int room_area;
  int room_height;
  SidesColor colors;
  std::string room_name;

public:
  Room(){};

  // setters
  void SetRoomArea(int room_area) { this->room_area = room_area; }
  void SetRoomHeight(int room_height) { this->room_height = room_height; }
  void SetRoomOneColor(std::string room_color) {
    colors.SetOneColor(room_color);
  }
  void SetWallsColor(std::string wall1, std::string wall2, std::string wall3,
                     std::string wall4) {
    colors.SetWallsColor(wall1, wall2, wall3, wall4);
  }
  void SetRoomName(std::string room_name) { this->room_name = room_name; }

  // getters
  int GetRoomArea() { return this->room_area; }
  int GetRoomHeight() { return this->room_height; }
  RoomColors GetRoomColors() { return colors; }
  std::string GetRoomName() { return this->room_name; }
};

class Elevator {
private:
  int width;
  int height;
  int max_people;
  int max_weight;
  RoomColors elevator_color;

public:
  Elevator(){};

  // setters
  void SetWidth(int width) { this->width = width; };
  void SetHeight(int height) { this->height = height; };
  void SetMaxPeople(int max_people) { this->max_people = max_people; };
  void SetMaxWeight(int max_weight) { this->max_weight = max_weight; };
  void SetElevatorColors(std::string elevator_color) {
    this->elevator_color.SetRoomColor(elevator_color);
  }
};

int main(int argc, char *argv[]) {
  Room r1;
  r1.SetRoomArea(30);
  r1.SetRoomHeight(13);
  r1.SetRoomColor("red");
  return 0;
}
