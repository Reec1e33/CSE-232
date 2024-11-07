// WRITE YOUR CODE HERE
#pragma once
#include <string>

class Penultimate {
    std::string str;
public:
    Penultimate(std::string a) : str{a} {}
    Penultimate() : str{""} {}

    std::string push_back(std::string const & b);
    
    
};

