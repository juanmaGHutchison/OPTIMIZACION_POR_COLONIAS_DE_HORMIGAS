#include "RATIONAL.hpp"

Rational_number::Rational_number():numerator_(1), denominator_(100) {}

Rational_number::Rational_number(float r, int d = 1): 
    numerator_ (r), 
    denominator_(d) {
        simplify();
}

Rational_number::Rational_number(const Rational_number& r):
  numerator_(r.numerator_), 
  denominator_(r.denominator_)
  {
    simplify();
  }

//explicit Rational_number::Rational_number(int n): numerator_(n), denominator_(1) {}

void Rational_number::modify_rational_number (int numerator, int denominator = 1) {
    if(denominator_ != 0) {
        numerator_ = numerator;
        denominator_ = denominator;
        simplify();
    }
}

void Rational_number::modify_rational_number_WITHOUT_SIMPLIFY (int numerator, int denominator = 1) {
    if(denominator_ != 0) {
        numerator_ = numerator;
        denominator_ = denominator;
    }
}

int Rational_number::numerator() const { return numerator_; }

int Rational_number::denominator() const { return denominator_; }

float Rational_number::resolv() const { return (numerator_ / denominator_); }

void Rational_number::from_str(String str) {
  String number = "";
  bool numerator = true;
  
  for(size_t i = 0; i < str.length(); i++) {
    if(str.charAt(i) != '/' && str.charAt(i) != 'E') {
      number += str.charAt(i);
    } else {
      if (numerator) {
        numerator_ = number.toInt();
        numerator = false;
        number = "";
      } else { 
        denominator_ = number.toInt();
        number = "";
      }
    }
  }
}


String Rational_number::toString() const { return (((String)numerator_) + "/" + ((String)denominator_)); }

void Rational_number::printR() const {
    Serial.print(numerator_);
    Serial.print(" / ");
    Serial.println(denominator_);
}

void Rational_number::simplify() {
    int prime_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19};

    for (size_t i = 0; i < 8; i++)
        if(((numerator_ % prime_numbers[i]) == 0) && ((denominator_ % prime_numbers[i]) == 0)) {
          numerator_ /= prime_numbers[i];
          denominator_ /= prime_numbers[i];
          i = -1;
        }
}

Rational_number Rational_number::operator = (const Rational_number& r) {  
  if(denominator_ != 0) {
    numerator_ = r.numerator_;
    denominator_ = r.denominator_;
    simplify();
  }
  
  return *this;
}

int mcd(int num1, int num2) {
    int mcd = 0; 
    int a = (num1 > num2)? num1 : num2;
    int b = (num1 < num2)? num1 : num2;
    do {
    mcd = b;
    b = a%b;
    a = mcd;
    } while(b != 0);
    
    return mcd;
}

int mcm(int num1, int num2) {
    int mcm = 0;
    int a = (num1 > num2)? num1 : num2;
    int b = (num1 < num2)? num1 : num2;
    mcm = (a/mcd(a,b))*b;
    return mcm;
}

Rational_number operator + (const Rational_number& r1, const Rational_number& r2) {
  Rational_number r;
  int mcm_ = mcm(r1.denominator(), r2.denominator());
  int numerator = (mcm_/r1.denominator()*r1.numerator()) + (mcm_/r2.denominator()*r2.numerator());
  

  r.modify_rational_number (
    (numerator),
    (mcm_)
  );

  if(r.denominator() == 0) { 
    Serial.println("Math Error, denominator = 0");
    r.modify_rational_number(0, 1);
  }
  
  return r;
}

Rational_number operator - (const Rational_number& r1, const Rational_number& r2) {
  Rational_number r;
  
  int mcm_ = mcm(r1.denominator(), r2.denominator());
  int numerator = (mcm_/r1.denominator()*r1.numerator()) - (mcm_/r2.denominator()*r2.numerator());
  

  r.modify_rational_number (
    (numerator),
    (mcm_)
  );

  if(r.denominator() == 0) { 
    Serial.println("Math Error, denominator = 0");
    r.modify_rational_number(0, 1);
  }

  return r;
}

Rational_number operator * (const Rational_number& r1, const Rational_number& r2) {
  Rational_number r;

  r.modify_rational_number (
    (r1.numerator() * r2.numerator()),
    (r1.denominator() * r2.denominator())
  );
  
  if(r.denominator() == 0) { 
    Serial.println("Math Error, denominator = 0");
    r.modify_rational_number(0, 1);
  }

  return r;
}

Rational_number operator / (const Rational_number& r1, const Rational_number& r2) {
  Rational_number r;

  r.modify_rational_number (
    (r1.numerator() * r2.denominator()),
    (r1.denominator() * r2.numerator())
  );

  if(r.denominator() == 0) { 
    Serial.println("Math Error, denominator = 0");
    r.modify_rational_number(0, 1);
  }

  return r;
}

bool operator > (const Rational_number& r1, const Rational_number& r2) {
  int mcm_ = mcm(r1.denominator(), r2.denominator());

  return (mcm_/r1.denominator()*r1.numerator()) > (mcm_/r2.denominator()*r2.numerator());
}

bool operator >= (const Rational_number& r1, const Rational_number& r2) {
  int mcm_ = mcm(r1.denominator(), r2.denominator());

  return ((mcm_/r1.denominator()*r1.numerator()) > (mcm_/r2.denominator()*r2.numerator()))
              ||
          r1 == r2
  ;
}

bool operator < (const Rational_number& r1, const Rational_number& r2) {
  int mcm_ = mcm(r1.denominator(), r2.denominator());

  return (mcm_/r1.denominator()*r1.numerator()) < (mcm_/r2.denominator()*r2.numerator());
}

bool operator <= (const Rational_number& r1, const Rational_number& r2) {
  int mcm_ = mcm(r1.denominator(), r2.denominator());

  return ((mcm_/r1.denominator()*r1.numerator()) < (mcm_/r2.denominator()*r2.numerator()))
              ||
          r1 == r2
  ;
}

bool operator == (const Rational_number& r1, const Rational_number& r2) {
  r1.simplify();
  r2.simplify();
  
  return ((r1.numerator() == r2.numerator()) && (r1.denominator() == r2.denominator()));
}
