#include "MOTOR_PWM.hpp"
MOTOR_PWM::MOTOR_PWM(int pwm): 
  IN1_(LN298_IN1), 
  IN2_(LN298_IN2), 
  IN3_(LN298_IN3), 
  IN4_(LN298_IN4),
  pwm_(pwm)
  {
    pinMode(IN1_, INPUT);
    pinMode(IN2_, INPUT);
    pinMode(IN3_, INPUT);
    pinMode(IN4_, INPUT);  
    analogWrite(IN1_, 0);
    analogWrite(IN2_, 0);
    analogWrite(IN3_, 0);
    analogWrite(IN4_, 0);
  }
void MOTOR_PWM::straight() {
  analogWrite(IN1_, pwm_);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, pwm_);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::left() {
  analogWrite(IN1_, 0);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, pwm_);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::right() {
  analogWrite(IN1_, pwm_);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, 0);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::back(){
  analogWrite(IN1_, 0);
  analogWrite(IN2_, pwm_);
  analogWrite(IN3_, 0);
  analogWrite(IN4_, pwm_);
}
void MOTOR_PWM::crossLeft(){
  analogWrite(IN1_, 0);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, pwm_);
  analogWrite(IN4_, 0);
  analogWrite(IN1_, 0);
  analogWrite(IN2_, pwm_);
  analogWrite(IN3_, pwm_);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::crossRight() {
  analogWrite(IN1_, pwm_);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, 0);
  analogWrite(IN4_, 0);  
  analogWrite(IN1_, pwm_);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, pwm_);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::backLeft() {
  analogWrite(IN1_, 0);
  analogWrite(IN2_, pwm_);
  analogWrite(IN3_, pwm_);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::backRight() {
  analogWrite(IN1_, pwm_);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, 0);
  analogWrite(IN4_, pwm_);
}
void MOTOR_PWM::turnBack(){
  analogWrite(IN1_, pwm_);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, 0);
  analogWrite(IN4_, pwm_);
}
void MOTOR_PWM::botStop(){
  analogWrite(IN1_, 0);
  analogWrite(IN2_, 0);
  analogWrite(IN3_, 0);
  analogWrite(IN4_, 0);
}
void MOTOR_PWM::roll_grades(int grades){
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
