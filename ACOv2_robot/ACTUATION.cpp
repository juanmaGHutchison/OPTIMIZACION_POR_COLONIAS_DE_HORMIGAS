#include "ACTUATION.hpp"
Actuation::Actuation(): 
  cny_left_(CNY_LEFT, 870),
  cny_right_(CNY_RIGHT, 870),
  cnys_(cny_left_, cny_right_),
  previous_grade_(0)
  {}
  void Actuation::Response(uint8_t grades, uint8_t correction, bool& toogle) {
    if(toogle) {
      //Serial.println("TOOGLE ROBOT");
      motor_.roll_grades(180);
      toogle = false; 
    }
    /*Serial.print("INPUT GRADES: ");
    Serial.println(grades);*/
    previous_grade_ = to_grades(grades);
    /*Serial.print("GRADES CONVERTED: ");
    Serial.println(previous_grade_);*/
    motor_.roll_grades(previous_grade_);
    if(cnys_.bothWhite()) {
      while(!cnys_.bothBlack()) {
      if(cnys_.leftBlack())
        while(!cnys_.bothBlack() && !cnys_.bothWhite())
          motor_.right(); 
      if(cnys_.rightBlack())
        while(!cnys_.bothBlack() && !cnys_.bothWhite())
          motor_.left();
      while(cnys_.bothWhite()) 
        motor_.straight();
      }
    }  
    while(!cnys_.bothWhite()){
      if(cnys_.leftWhite())
        while(!cnys_.bothBlack() && !cnys_.bothWhite())
          motor_.right();
      if(cnys_.rightWhite())
        while(!cnys_.bothBlack() && !cnys_.bothWhite())
          motor_.left();
       while(cnys_.bothBlack()) 
          motor_.straight();
    }
    motor_.botStop();
    delay(2000);
    while(!cnys_.bothBlack()) {
      if(cnys_.leftBlack())
        while(!cnys_.bothBlack() && !cnys_.bothWhite())
          motor_.right(); 
      if(cnys_.rightBlack())
        while(!cnys_.bothBlack() && !cnys_.bothWhite())
          motor_.left();
      while(cnys_.bothWhite()) 
        motor_.straight();
    }
    motor_.botStop();
    delay(2000);
    /*Serial.print("INPUT CORRECTION: ");
    Serial.println(correction);*/
    motor_.roll_grades(to_grades(correction));
  }
  int Actuation::to_grades(uint8_t matrix_grades) const {
    int grades_to_roll = 0;
    switch(matrix_grades) {
        case 0:
          grades_to_roll = 0;
        break;
        case 1:
          grades_to_roll = 90;
        break;
        case 2:
          grades_to_roll = 180;
        break;
        case 3:
          grades_to_roll = 270;
        break;
      }
      return grades_to_roll;
  }
    void Actuation::straighten() {
      /*int grades_to_roll;
  
      switch(previous_grade_) {
        case 90:
          grades_to_roll = 270;
        break;
        case 270:
          grades_to_roll = 90;
        break;
        default:
          grades_to_roll = previous_grade_;
        break;
      }
      Serial.print("GRADES TO ROLL TO STRAIGHT BOT: ");
      Serial.println(grades_to_roll);
      motor_.roll_grades(grades_to_roll);
     */   
    }
    String Actuation::previous_grade() const {
      return String(previous_grade_);
    } 
