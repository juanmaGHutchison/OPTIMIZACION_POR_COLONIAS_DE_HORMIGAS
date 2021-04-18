#ifndef x2CNY_HPP_
#define x2CNY_HPP_
#include "Arduino.h"
#include "CNY.hpp"

class x2CNY {
  public:
    //CONSTRUCTOR
    /* 2xCNY()
     *  Precondition: -
     *  Postcondition: Creates a new CNY object which includes 2 CNYs, 
     *    one each to the other. (left, right)
     */
    x2CNY(const CNY&, const CNY&);
    //GETTER
    /* bool bothWhite() const
     *  Precondition: -
     *  Postcondition: returns TRUE if left CNY and right CNY are focusing 
     *    a white background, any other case returns FALSE
     */
    bool bothWhite() const;
    /* bool bothBlack() const
     *  Precondition: -
     *  Postcondition: returns TRUE if left CNY and right CNY are focusing a black background, 
     *    any other case returns FALSE
     */
    bool bothBlack() const;
    /* bool leftWhiteRightBlack() const
     *  Precondition: -
     *  Postcondition: returns TRUE if left CNY is focusing a white background 
     *    and right CNY is focusing a black background, any other case returns FALSE
     */
    bool leftWhiteRightBlack() const;
    /* bool leftBlackRightWhite() const
     *  Precondition: -
     *  Postcondition: returns TRUE if left CNY is focusing a black background 
     *    and right CNY is focusing a white background, any other case returns FALSE
     */
    bool leftBlackRightWhite() const;
    /* bool leftWhite() const
     *  Precondition: -
     *  Postcondition: returns TRUE if left CNY focuses a white background, 
     *    any other case returns FALSE and does not matter about right CNY value
     */
    bool leftWhite() const;
    /* bool leftBlack() const
     *  Precondition: -
     *  Postcondition: returns TRUE if left CNY is focusing a black background, 
     *    any other case returns FALSE and doesn't matter about right CNY value
     */
    bool leftBlack() const;
    /* bool rightWhiteLeftBlack() const
     *  Precondition: -
     *  Postcondition: returns TRUE if right CNY is focusing a white background 
     *    and left CNY is focusing a black background, any other case returns FALSE
     */
    bool rightWhiteLeftBlack() const;
    /* bool rightBlackLeftWhite() const
     *  Precondition: -
     *  Postcondition: returns TRUE if right CNY is focusing a black background 
     *    and left CNY is focusing a white background, any other case returns FALSE
     */
    bool rightBlackLeftWhite() const;
    /* bool rightWhite() const
     *  Precondition: -
     *  Postcondition: returns TRUE if right CNY is focusing a white background, 
     *    any other case returns FALSE and does not matter about left CNY value
     */
    bool rightWhite() const;
    /*bool rightBlack()const
     * Precondition: -
     * Postcondition: returns TRUE if right CNY is focusing a black background, 
     *  any other case returns FALSE and does not matter about left CNY value
     */
    bool rightBlack() const;
  private:
    CNY CNY_LEFT_, CNY_RIGHT_;
};
#endif
