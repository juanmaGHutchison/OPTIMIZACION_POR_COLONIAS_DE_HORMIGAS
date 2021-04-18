#include "rational.h"
Rational_number::Rational_number():numerator_(1), denominator_(100) {}
Rational_number::Rational_number(int n, int d): numerator_(n), denominator_(d) {}
Rational_number::Rational_number(float f) {
        int pot = 10;
        numerator_ = int (f);
        denominator_ = 1;
        while(numerator_ < 100) {
            numerator_ = f * pot;
            denominator_ = pot;
            pot *= 10;
        }
        simplify();
}
Rational_number::Rational_number(const Rational_number& r):
  numerator_(r.numerator_), 
  denominator_(r.denominator_)
  {
    simplify();
  }
void Rational_number::modify_rational_number (int numerator, int denominator) {
    if(denominator_ != 0) {
        numerator_ = numerator;
        denominator_ = denominator;
        simplify();
    }
}
void Rational_number::modify_rational_number_WITHOUT_SIMPLIFY (int numerator, int denominator) {
    if(denominator_ != 0) {
        numerator_ = numerator;
        denominator_ = denominator;
    }
}
int Rational_number::numerator() const { return numerator_; }
int Rational_number::denominator() const { return denominator_; }
float Rational_number::resolv() const { return (float(numerator_) / float(denominator_)); }
Rational_number Rational_number::from_float_to_rational(float f) {
    qDebug() << "float val: " << f;
    int pot = 10;
    numerator_ = int (f);
    denominator_ = 1;
    while(numerator_ < 100) {
        numerator_ = f * pot;
        denominator_ = pot;
        pot *= 10;
    }
    simplify();
    return *this;
}
QString Rational_number::toString() const { return (QString::number(numerator_) + "/" + QString::number(denominator_));}
void Rational_number::simplify() {
    int prime_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (size_t i = 0; i < 8; i++)
        if(((numerator_ % prime_numbers[i]) == 0) && ((denominator_ % prime_numbers[i]) == 0)) {
          numerator_ /= prime_numbers[i];
          denominator_ /= prime_numbers[i];
          i = -1;
        }
    numerator_ %= 32000;
    denominator_ %= 32000;
}
Rational_number Rational_number::simplify() const {
    int prime_numbers[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int n = numerator_;
    int d = denominator_;
    for (size_t i = 0; i < 8; i++)
        if(((n % prime_numbers[i]) == 0) && ((d % prime_numbers[i]) == 0)) {
          n /= prime_numbers[i];
          d /= prime_numbers[i];
          i = -1;
        }
    n %= 32000;
    d %= 32000;
    return Rational_number(n, d);
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
  if(r.denominator() == 0)
    r.modify_rational_number(0, 1);
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
  if(r.denominator() == 0)
    r.modify_rational_number(0, 1);
  return r;
}
Rational_number operator * (const Rational_number& r1, const Rational_number& r2) {
  Rational_number r;
  r.modify_rational_number (
    (r1.numerator() * r2.numerator()),
    (r1.denominator() * r2.denominator())
  );
  if(r.denominator() == 0)
    r.modify_rational_number(0, 1);
  return r;
}
Rational_number operator / (const Rational_number& r1, const Rational_number& r2) {
  Rational_number r;
  r.modify_rational_number (
    (r1.numerator() * r2.denominator()),
    (r1.denominator() * r2.numerator())
  );
  if(r.denominator() == 0)
    r.modify_rational_number(0, 1);
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
  Rational_number rc1, rc2;
  rc1 = r1.simplify();
  rc2 = r2.simplify();
  return ((rc1.numerator() == rc2.numerator()) && (rc1.denominator() == rc2.denominator()));
}
