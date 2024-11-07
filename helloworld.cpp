#include <iostream>
#include <string>

int main() {
  int num = 0;
  std::cout << & num << std::endl;
  int * ptr_int = &num;
  std::cout << *ptr_int << std::endl;
  

}