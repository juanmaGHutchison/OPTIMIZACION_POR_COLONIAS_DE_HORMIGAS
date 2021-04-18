#include "2xCNY.hpp"
x2CNY::x2CNY(const CNY& CNY_LEFT, const CNY& CNY_RIGHT): 
  CNY_LEFT_(CNY_LEFT),
  CNY_RIGHT_(CNY_RIGHT)
  {}
bool x2CNY::bothWhite() const {
  return (CNY_LEFT_.isWhite() && CNY_RIGHT_.isWhite());
}
bool x2CNY::bothBlack() const {
  return (CNY_LEFT_.isBlack() && CNY_RIGHT_.isBlack());
}
bool x2CNY::leftWhiteRightBlack() const {
  return (CNY_LEFT_.isWhite() && CNY_RIGHT_.isBlack());
}
bool x2CNY::leftBlackRightWhite() const {
  return (CNY_LEFT_.isBlack() && CNY_RIGHT_.isWhite());
}
bool x2CNY::leftWhite() const {
  return (CNY_LEFT_.isWhite());
}
bool x2CNY::leftBlack() const {
  return (CNY_LEFT_.isBlack());
}
bool x2CNY::rightWhiteLeftBlack() const {
  return (CNY_RIGHT_.isWhite() && CNY_LEFT_.isBlack());
}
bool x2CNY::rightBlackLeftWhite() const {
  return (CNY_RIGHT_.isBlack() && CNY_LEFT_.isWhite());
}
bool x2CNY::rightWhite() const {
  return (CNY_RIGHT_.isWhite());
}
bool x2CNY::rightBlack() const {
  return (CNY_RIGHT_.isBlack());
}
