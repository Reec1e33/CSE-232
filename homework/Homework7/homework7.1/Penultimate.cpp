#include <string>
#include "Penultimate.hpp"
#include <vector>




std::string Penultimate::push_back(std::string const & b){
    
    std::string output = str;
    str = b;
    return output;
}
