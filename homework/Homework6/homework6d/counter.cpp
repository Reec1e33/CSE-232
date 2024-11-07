// WRITE YOUR CODE HERE
#include "name_checker.hpp"
#include "counter.hpp"
#include <vector>
#include <string>
#include <stdexcept>
std::vector<int> CountExceptions(std::vector<std::string> const & input) {
  std::vector<int> output1{0,0,0};
  for (std::string v: input) {
    

    try{
      CheckName(v);
    }catch( std::invalid_argument const&){
      output1.at(0) +=1;
    }catch( std::length_error const&) {
      output1.at(1) +=1;
    }catch( std::out_of_range const&) {
      output1.at(2) +=1;
    }
  

    
      
  }
  return output1;
}