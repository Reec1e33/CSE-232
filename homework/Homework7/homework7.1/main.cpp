#include "Penultimate.hpp"
#include <string>
#include <cassert>
#include <iostream>


int main() {
  Penultimate p("first");
  std::string s = p.push_back("second"); // s is "first"
  std::cout << s << std::endl;
  assert(s == "first");
  std::cout << s << std::endl;

  p.push_back("Third"); // returns "second"
  std::cout << s << std::endl;

  s = p.push_back("last"); // returns "Third"
  std::cout << s << std::endl;

  assert(s == "Third");

  
}