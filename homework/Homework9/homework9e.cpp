// WRITE YOUR CODE HERE
#include <vector>
#include <string>
#include <iostream>

template <typename T>

class EveryOther{
  std::vector<T> everyother;
  bool add = true;
public:
  EveryOther() : everyother{} {}
  EveryOther(std::initializer_list<T> v) {

    for (T const & elem : v){
      if ( add == true) {
        everyother.push_back(elem);
      }
      add = !add;
    }
  }

  void push_back(T const & element) {
    if (add){
      everyother.push_back(element);
    }
    add = !add;
  }

  size_t size(){
    return everyother.size();
  }

  friend std::ostream & operator<<(std::ostream& os, EveryOther<T> & everyother){
    os << "EveryOther(";
    for (size_t i = 0; i < everyother.everyother.size(); ++i){
      os << everyother.everyother.at(i) << ", ";
    }
    os << ")";
    return os;
  }


};



