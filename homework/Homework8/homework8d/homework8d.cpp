#include "homework8d.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Price Price::operator+(Price const& p) const{
    Price p1 = input + p.input;
    return p1;
}

Price& Price::operator+=(const Price& p){
    input += p.input;
    return *this;
}

Price Price::operator-(const Price& p) const{
    return Price(input - p.input);
}

Price& Price::operator-=(const Price& p){
    input -= p.input;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Price& p){
    os << std::fixed << std::setprecision(2) << "$" << p.input;

    return os;
}
std::istream& operator>>(std::istream& is, Price& p) {
    char dollarSign;
    double value;

    is >> dollarSign >> value;

    if (dollarSign == '$') {
        p.input = value;
    }

    return is;
}
