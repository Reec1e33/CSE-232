// Note: This file is not tested by the autograder

#include "header.hpp"

#include <iostream>
#include <list>
#include <cassert>

int main() {
	
  Stack s;
  s.push('a');
  assert(s.top() == 'a');
  s.pop();

  return 0;
}