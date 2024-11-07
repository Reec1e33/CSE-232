#include "lecture7complex.h"
#include <cmath>
using std::pow, std::sqrt;


double AbsoluteValue(complex const & c){
    // Square the real and imaginary components,
    // sum them 
    //return the square root of that sum
    return sqrt(pow(c.real(), 2) + pow(c.imag(),2));


}

bool complex::operator<(complex const & b){
    double abs_a{AbsoluteValue(*this)};
    double abs_b{AbsoluteValue(b)};
    return abs_a < abs_b;

}
