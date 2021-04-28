#include "MOTOR.hpp"
MOTOR::MOTOR(): 
  IN1_(LN298_IN1), 
  IN2_(LN298_IN2), 
  IN3_(LN298_IN3), 
  IN4_(LN298_IN4)
  {
    pinMode(IN1_, INPUT);
    pinMode(IN2_, INPUT);
    pinMode(IN3_, INPUT);
    pinMode(IN4_, INPUT);  
    digitalWrite(IN1_, LOW);
    digitalWrite(IN2_, LOW);
    digitalWrite(IN3_, LOW);
    digitalWrite(IN4_, LOW);
  }
void MOTOR::straight() {
  digitalWrite(IN1_, HIGH);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, HIGH);
  digitalWrite(IN4_, LOW);
}
void MOTOR::left() {
  digitalWrite(IN1_, LOW);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, HIGH);
  digitalWrite(IN4_, LOW);
}
void MOTOR::right() {
  digitalWrite(IN1_, HIGH);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, LOW);
  digitalWrite(IN4_, LOW);
}
void MOTOR::back(){
  digitalWrite(IN1_, LOW);
  digitalWrite(IN2_, HIGH);
  digitalWrite(IN3_, LOW);
  digitalWrite(IN4_, HIGH);
}
void MOTOR::crossLeft(){
  digitalWrite(IN1_, LOW);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, HIGH);
  digitalWrite(IN4_, LOW);
  digitalWrite(IN1_, LOW);
  digitalWrite(IN2_, HIGH);
  digitalWrite(IN3_, HIGH);
  digitalWrite(IN4_, LOW);
}
void MOTOR::crossRight() {
  digitalWrite(IN1_, HIGH);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, LOW);
  digitalWrite(IN4_, LOW);  
  digitalWrite(IN1_, HIGH);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, HIGH);
  digitalWrite(IN4_, LOW);
}
void MOTOR::backLeft() {
  digitalWrite(IN1_, LOW);
  digitalWrite(IN2_, HIGH);
  digitalWrite(IN3_, HIGH);
  digitalWrite(IN4_, LOW);
}
void MOTOR::backRight() {
  digitalWrite(IN1_, HIGH);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, LOW);
  digitalWrite(IN4_, HIGH);
}
void MOTOR::turnBack(){
  digitalWrite(IN1_, HIGH);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, LOW);
  digitalWrite(IN4_, HIGH);
}
void MOTOR::botStop(){
  digitalWrite(IN1_, LOW);
  digitalWrite(IN2_, LOW);
  digitalWrite(IN3_, LOW);
  digitalWrite(IN4_, LOW);
}
void MOTOR::roll_grades(int grades){
  switch(grades){
    case 90:
      left();
      backLeft();
      delay(1170);
      //delay(360); //ATOMICA
      //delay(1400); //BATERIA GRANDE
      botStop();
    break;   
    case 180:
      right();
      backRight();
      delay(2500);
      //delay(730); //ATOMICA
      //delay(2688);  //BATERIA GRANDE
      botStop();
    break;    
    case 270:
      right();
      backRight();
      delay(1200);
      //delay(360); //ATOMICA
      //delay(1400);  //BATERIA GRANDE
      botStop();
    break;
  }
}
