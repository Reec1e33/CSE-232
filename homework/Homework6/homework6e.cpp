// WRITE YOUR CODE HERE
#include <vector>
#include <iostream>
#include <exception>

int SumButScared(std::vector<int> const & vector1) {
  int sum = 0;
  for (int i : vector1) {
    if ((i % 13) == 0) {
      throw std::invalid_argument{"vector1: contains multiple of 13"};
      return i;
    }else{
      sum += i;

    }
  
  }
  return sum;
}