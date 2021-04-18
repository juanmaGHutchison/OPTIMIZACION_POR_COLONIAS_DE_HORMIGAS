#ifndef RATIONAL_NUMBER_HPP_
#define RATIONAL_NUMBER_HPP_
#include <cstdint>
#include <QString>
#include <QDebug>
struct Rational_number {         
  Rational_number();
  Rational_number(int, int = 1);
  explicit Rational_number(float);
  Rational_number(const Rational_number&);
  void modify_rational_number (int, int = 1);
  void modify_rational_number_WITHOUT_SIMPLIFY (int, int = 1);
  int numerator() const;
  int denominator() const;
  float resolv() const;
  Rational_number from_float_to_rational(float);
  //String toString() const;
  void printR() const;
  void simplify();
  Rational_number simplify() const;
  Rational_number operator = (const Rational_number&);
  QString toString() const;
  private:
    int numerator_, denominator_;
};
int mcd(int, int);
int mcm(int, int);
Rational_number operator + (const Rational_number&, const Rational_number&);
Rational_number operator - (const Rational_number&, const Rational_number&);
Rational_number operator * (const Rational_number&, const Rational_number&);
Rational_number operator / (const Rational_number&, const Rational_number&);
bool operator > (const Rational_number&, const Rational_number&);
bool operator >= (const Rational_number&, const Rational_number&);
bool operator < (const Rational_number&, const Rational_number&);
bool operator <= (const Rational_number&, const Rational_number&);
bool operator == (const Rational_number&, const Rational_number&);
#endif
