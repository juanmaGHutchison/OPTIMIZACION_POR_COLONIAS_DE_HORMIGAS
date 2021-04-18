#ifndef ACTUATION_HPP_
#define ACTUATION_HPP_
#include "Arduino.h"
#include "MOTOR.hpp"
#include "CNY.hpp"
#include "2xCNY.hpp"
#include "COMMON_TYPES.hpp"
class Actuation {
    public:
        //CONSTRUCTOR
        Actuation();
        //ACTUATION
        void Response(uint8_t grades, uint8_t correction, bool& toogle);
        void straighten();
        String previous_grade() const;
        int to_grades(uint8_t) const;
    private:
        MOTOR motor_;
        CNY cny_left_, cny_right_;
        x2CNY cnys_;
        int previous_grade_;
};
#endif
