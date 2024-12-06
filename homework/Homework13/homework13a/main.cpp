// Note: This file is not tested by the autograder

#include "header.hpp"

#include <iostream>
#include <list>
#include <cassert>

int main() {
	
  std::list<int> my_list = {1, 4, 5};
  int result = center(my_list.cbegin(), my_list.cend());
  std::cout << result << std::endl;
  assert(result == 4);


  return 0;
}