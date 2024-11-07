// WRITE YOUR CODE HERE
#include "homework6b.hpp"
#include <string>



std::string Repeat(std::string const & input){
    return input + " " + input;
}

int Repeat(int const & input) {
    return input*2;
}

std::string Repeat( char const & input ) {
    std::string output;
    output += input;
    output += input;
    return output;

}