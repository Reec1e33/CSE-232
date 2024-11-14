// WRITE YOUR CODE HERE
#include <vector>
std::vector<int>::const_iterator FindSmallestIndexRange(std::vector<int> const & vec, int const & front, int const & back);

template <typename T>

void DoubleIteratorRange(T iter1, T iter2){
  while( iter1 < iter2){
    *iter1 *= 2;
    ++iter1;
  }
}
