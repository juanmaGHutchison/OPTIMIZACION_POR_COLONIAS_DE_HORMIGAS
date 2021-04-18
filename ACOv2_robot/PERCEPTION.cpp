#include "PERCEPTION.hpp"
String Perception::color_str() const {
  String color_str;
  switch(tsc3200_.getLastColour()){
    case Color::RED:
      color_str = "Red";
    break;
    case Color::GREEN:
      color_str = "Green";
    break;
    case Color::BLUE:
      color_str = "Blue";
    break;
    case Color::NONE:
      color_str = "None";
    break;
  }
  return color_str;
}
Color Perception::Perceive() {
    return tsc3200_.getColor();
}
