#ifndef ACO_INO_
#define ACO_INO_
#include "PINS.hpp"
#include "MAIN_CONTROLLER.hpp"
Main_controller main_controller;
void setup() {
  Serial.begin(9600); 
}
void loop() {
  main_controller.run_main_controller();
}
#endif
