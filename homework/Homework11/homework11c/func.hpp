// WRITE YOUR CODE HERE
#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

template <typename T>

std::vector<T> MaxVector(std::vector<T> vec1, std::vector<T> vec2) {
  size_t vec1Size = vec1.size();
  size_t vec2Size = vec2.size();
  

  if (vec1Size > vec2Size){
    std::transform(vec2.begin(), vec2.end(), vec1.begin(), vec1.begin(), [](T v1, T v2){return std::max(v1,v2);});

    return vec1;
  }else{
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec2.begin(), [](T v2, T v1){return std::max(v1,v2);} );
    return vec2;
  }
  
  
  

}
