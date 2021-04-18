#include "MAIN_CONTROLLER.hpp"
void Main_controller::run_main_controller() {
  Color readen;
  uint8_t grades; 
  readen = perception_.Perceive();
  //perception_.color_str();
  grades = logic_.Proceed(readen); 
  actuation_.Response(grades, logic_.correction(),logic_.toogle());
}
Perception Main_controller::this_perception() const {
  return perception_;
}
Logic Main_controller::this_logic() const {
  return logic_;
}
Actuation Main_controller::this_actuation() const {
  return actuation_;
}
