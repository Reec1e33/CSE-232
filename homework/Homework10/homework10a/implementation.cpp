// WRITE YOUR CODE HERE
#include "header.hpp"
#include <iostream>
#include <vector>
std::vector<int>::const_iterator FindSmallestIndexRange(std::vector<int> const & vec, int const & front, int const & back){
  std::vector<int>::const_iterator iter {vec.cbegin() + front};
  std::vector<int>::const_iterator stop {vec.cbegin() + back + 1};

  if (static_cast<int>(vec.size()) < back + 1){
    stop = vec.cend();
  }
  for (std::vector<int>::const_iterator start {vec.cbegin() + front}; (start != stop) ; ++start){
    if (*start < *iter)  {
      iter = start;
    }
  }

  return iter;

}




int main() {
  // CHECK FindSmallestIndexRange
  std::vector<int> data1 = {6, 1, 5, 4, 3, 2, -1};
  std::vector<int>::const_iterator iter_smallest = FindSmallestIndexRange(data1, 2, 5);
  std::cout << "Smallest int:\t" << *iter_smallest << std::endl;


  std::vector<int> data2 =   {6, 1, 5, 0, 3, 2, 1};
  std::vector<int>::const_iterator iter_smallest2 = FindSmallestIndexRange(data2, 4, 7);
  std::cout << "Smallest int:\t" << *iter_smallest2 << std::endl;

  
  return 0;
}