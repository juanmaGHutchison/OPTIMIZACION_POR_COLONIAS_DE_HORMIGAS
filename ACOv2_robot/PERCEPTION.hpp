#ifndef PERCEPTION_HPP_
#define PERCEPTION_HPP_
#include "Arduino.h"
#include "TSC3200.hpp"
#include "COMMON_TYPES.hpp"
class Perception {
    public:
        //DEFAULT CONSTRUCTOR       
        //PERCEPTION
         /*
          * TSC3200::Color Perceive();
          * Precondition: -
          * Postcondition: Returns the color that 
          *   it read 
          */
          Color Perceive();
          String color_str() const;
    private:
        TSC3200 tsc3200_;
};
#endif
