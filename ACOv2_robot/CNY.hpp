#ifndef CNY_HPP_
#define CNY_HPP_
#include "Arduino.h"
#include "PINS.hpp"
class CNY{
    public:
        //CONSTRUCTOR
        /* CNY(uint8_t CNY_PIN, uint8_t SILL)
         * Precondition: -
         * Postcondition: Creates a new CNY object, sill parameter 
         *  is for calibration of the CNY, by default 512. CNY_PIN is 
         *  the Arduino pin that this CNY uses.
         */
        CNY(uint8_t, float = 512);
        //GETTER
        /* bool isWhite() const;
         * Precondition: -
         * Postcondition: Returns TRUE if the CNY is over white, else returns FALSE
        */
        bool isWhite() const;
        /* bool isBlack() const;
         * Precondition: -
         * Postcondition: Returns TRUE if the CNY is over black, else returns FALSE
        */
        bool isBlack() const;     
    private:
        uint8_t CNY_;
        float SILL_;
};
#endif
