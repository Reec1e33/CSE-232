// WRITE YOUR CODE HERE
#include "homework8c.h"
#include <string>
#include <iostream>
#include <sstream>


  
std::string LispExpression::PrettyPrint() const{
  std::string word;
  std::ostringstream oss;
  std::string spaces{""};
  std::stringstream ss{le};

  while (ss >> word){
    
    if (word == ")"){
      spaces.pop_back();
    }
    
    

    oss << spaces << word << std::endl;
    if (word == "("){
      spaces += " ";
    }
    if (spaces == ""){
        break;
    }
  }
  return oss.str();
}