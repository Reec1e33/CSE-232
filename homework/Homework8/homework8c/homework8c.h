// WRITE YOUR CODE HERE
#pragma once
#include <string>


class LispExpression{
  std::string le = "";
public:

LispExpression(std::string str) : le{str} {}
LispExpression() : le{""} {}

std::string PrettyPrint() const;


};