#ifndef PINS_HPP_
#define PINS_HPP_
//DEFINITION OF PINS for parched board, featuring PWM for al LN298 inputs
/*************CNYx2*********************
 *  ARDUINO PIN   NAME                 *
 *    A1          CNY_LEFT             *
 *    A2          CNY_RIGHT            *
 ***************************************/
 /*************BLUETOOTH****************
 *  ARDUINO PIN   NAME                 *
 *    D1/TX       BLUETOOTH_TRANSMIT   *
 *    D2/RX       BLUETOOTH_RECEIVE    *
 ***************************************/
 /*************COLOR_SENSOR*************
 *  ARDUINO PIN   NAME                 *
 *    D8          S1                   *
 *    D9          S0                   *
 *    D10         S3                   *
 *    D11         S2                   *
 *    D12         OUT                  *
 ***************************************/
 /*************LN298********************
 *  ARDUINO PIN   NAME                 *
 *    D5          IN1                  *
 *    D4          IN2                  *
 *    D3          IN3                  *
 *    D2          IN4                  *
 ***************************************/
//CNYx2
#define CNY_LEFT A2
#define CNY_RIGHT A1
//BLUETOOTH
#define BLUETOOTH_TRANSMIT 1
#define BLUETOOTH_RECEIVE 2
//COLOR SENSOR
#define S1 8
#define S0 7
#define S3 10
#define S2 11
#define OUT 12
//LN298
#define LN298_IN1 5
#define LN298_IN2 9
#define LN298_IN3 3
#define LN298_IN4 6
#endif
