#include <iostream>
#include <string>
#include <cctype>

using std::string;

void Capitalize(string & s);

void MakeExciting(string s);

int main() {
  int * x = new int{0};
  //new returns a pointer to dynamically allocated memory
  //this objects lives until delete is called on the pointer

  std::cout << *x << std::endl;

  delete x;

  string * words = new string[40]{"CSE","232"};
  //new can be used to dynamically allocate arrays too
  // the initialization is optional
  // just like for regular variables

  std::cout << words[1] << std::endl;

  delete [] words;
  //note the [] required to delete dynamicaly
  // allocated arrays
  string name{"mal"};
  Capitalize(name);
  MakeExciting(name);
}

void Capitalize(string & s) {
  s.at(0) = std::toupper(s.at(0));
  std::cout << "s.at(0) is now : " << s.at(0) << std::endl;
}

void MakeExciting(string const s) {
  std::cout << s << "!!!!!!!!!" << std::endl;

}