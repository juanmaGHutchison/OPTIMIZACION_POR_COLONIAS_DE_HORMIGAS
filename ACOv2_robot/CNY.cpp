#include "CNY.hpp"
CNY::CNY(uint8_t CNY_PIN, float SILL):
    CNY_(CNY_PIN), SILL_(SILL) {}
bool CNY::isWhite() const {
    uint32_t cny;
    cny = analogRead(CNY_);
    return SILL_ >= cny;
}
bool CNY::isBlack() const {
    uint32_t cny;
    cny = analogRead(CNY_);
    return SILL_ < cny;
}
