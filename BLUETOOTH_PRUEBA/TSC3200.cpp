#include "TSC3200.hpp"

TSC3200::TSC3200(): 
    color_ (Color::NONE),
    S0_ (S0),
    S1_ (S1),
    S2_ (S2),
    S3_ (S3),
    OUT_ (OUT)  {
        pinMode (S0_, OUTPUT);
        pinMode (S1_, OUTPUT);
        pinMode (S2_, OUTPUT);
        pinMode (S3_, OUTPUT);
        pinMode (OUT_, INPUT);

        digitalWrite (S0_, HIGH);
        digitalWrite (S1_, HIGH);
    }

Color TSC3200::getColor() {
    byte countRed, countBlue, countGreen;

    for(int i = 0; i < 50; ++i){
          digitalWrite(S2_, LOW);
          digitalWrite(S3_, LOW);
          countRed = pulseIn(OUT_, digitalRead(OUT_) == HIGH ? LOW : HIGH);
          digitalWrite(S3_, HIGH);
          countBlue = pulseIn(OUT_, digitalRead(OUT_) == HIGH ? LOW : HIGH);
          digitalWrite(S2_, HIGH);
          countGreen = pulseIn(OUT_, digitalRead(OUT_) == HIGH ? LOW : HIGH);
    } 

    if (countRed < countBlue && countRed < countGreen && countRed < 80) color_ = Color::RED;
    else if (countBlue < countRed && countBlue < countGreen) color_ = Color::BLUE;
    else /*if (countGreen < countRed && countGreen < countBlue)*/ color_ = Color::GREEN;

    return color_;
}

Color TSC3200::getLastColour() const {
  return color_;
}
