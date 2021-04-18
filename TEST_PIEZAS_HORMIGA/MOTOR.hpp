#ifndef MOTOR_HPP_
#define MOTOR_HPP_

#include "Arduino.h"

#include "PINS.hpp"

class MOTOR {
    public:
      //CONSTRUCTOR
      /* MOTOR()
       *  Precondition: -
       *  Postcondition: Creates a new MOTOR object
       */
      MOTOR();
      
      //END CONSTRUCTOR
      
      //SETTERS
      /* void straight()
       *  Precondition: -
       *  Postcondition: Makes the bot move straight      
      */
      void straight();

      /* void left()
       *  Precondition: -
       *  Postcondition: Makes the bot turn left      
      */
      void left();

      /* void right()
       *  Precondition: -
       *  Postcondition: Makes the bot turn right
       */
      void right();

      /* void back()
       *  Precondition: -
       *  Postcondition: Makes the bot move backwards
       */
      void back();

      /* void crossLeft()
       *  Precondition: -
       *  Postcondition: Turns the bot left and straight
       */
      void crossLeft();

      /*void crossRight()
       * Precondition: -
       * Postcondition: Turns the bot right and straight
       */
      void crossRight();

      /*void backRight()
       * Precondition: -
       * Postcondition: Turns the bot right foward and left backwards at the same time
       */
      void backRight();

      /*void backLeft()
       * Precondition: -
       * Postcondition: Turns the bot left foward and right backwards at the same time
       */
      void backLeft();

      /* void turnBack()
       *  Precondition: -
       *  Postcondition: Makes the bot turn the way back from where it came
       */
      void turnBack();

      /* void botStop()
       *  Precondition: -
       *  Postcondition: if bot is running, it stops it, else it does nothing.
       */
      void botStop();
      
      //END SETTERS
    private:
      uint8_t IN1_, IN2_, IN3_, IN4_;
};

#endif
