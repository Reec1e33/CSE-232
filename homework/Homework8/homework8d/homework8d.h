// WRITE YOUR CODE HERE
#pragma once
#include <iostream>
#include <sstream>


class Price{
  double input;
public:
  Price(double in) : input{in} {}
  Price() : input{0.00} {}


  Price operator+(Price const& p) const;
  Price& operator+=(const Price& p);
  Price operator-(const Price& p) const;
  Price& operator-=(const Price& p);


  friend std::ostream& operator<<(std::ostream& os, const Price& p);
  friend std::istream& operator>>(std::istream& is, Price& p);




};