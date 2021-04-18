#include "MAIN_CONTROLLER.hpp"
void Main_controller::run_main_controller() {
  Color readen;
  uint8_t grades;
  String on_transmit = "0";
  char junk;
  //readen = perception_.Perceive();
  //if(logic_.isHome(readen)) {
  Path p;
        p.add_path(1);     
        p.add_path(5);
      p.add_path(3);
      /*p.add_path(2);
      p.add_path(4);
      p.add_path(3);*/
      /*p.add_path(2);
      p.add_path(5);
      p.add_path(3);*/
      /*while(on_transmit == "0") {
        //Serial.println("Vamos a ver...");
        if(Serial.available() && continue_ == 'y') {
          on_transmit = "1";
          //Serial.println("Dentro");
        }
      }*/
      on_transmit = "1";
      while(Serial.available() && on_transmit == "1") {   
        //Serial.println("HOLAA");
        while(inputString_ != "p") {
          inChar_ = (char)Serial.read();
          inputString_ = inChar_;
        }
        Serial.write(p.path().c_str());
        inputString_ = "";
        do {
          if(Serial.available()) {
            inChar_ = (char)Serial.read();
            inputString_ += inChar_;
          }
        } while(inChar_ != 'E');
        on_transmit = "0";
        continue_ = 'n';
        while(Serial.available() > 0) junk = Serial.read();
    }
    logic_.modify_pheromones(inputString_);
    inChar_ = 'X';
    //logic_.print_pheromones();
    p.clear_path();
  //}
  //grades = logic_.Proceed(readen);
  //actuation_.Response(grades, logic_.correction(),logic_.toogle());
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
