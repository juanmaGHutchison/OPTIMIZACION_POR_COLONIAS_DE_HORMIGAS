#ifndef TSC3200_HPP_
#define TSC3200_HPP_

#include "Arduino.h"

#include "PINS.hpp"
#include "COMMON_TYPES.hpp"

class TSC3200 {
    public:
        //CONSTRUCTOR
        /*
        * TSC3200()
        * Precondition: -
        * Postcondition: Creates a new TSC3200 object
        */
        TSC3200();

        /*
        * Color getColour();
        * Precondition: -
        * Postcondition: returns the readen color
        */
        Color getColor();

        /*
         * Color getLastColour() const;
         * Precondition: -
         * Postcondition: Returns the las color that the sensor TSC3200 read
         */
         Color getLastColour() const;

    private:
        Color color_;
        uint8_t S0_, S1_, S2_, S3_, OUT_;
};

#endif
