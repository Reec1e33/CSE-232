#pragma once
#include <vector>
#include <memory>

template <typename T>
std::vector<T> ArrayToVector(T* array, size_t size) {
  std::vector<T> output;
  for (size_t i = 0; i < size; ++i){
    output.push_back(array[i]);
  }
  delete [] array;
  return output;
}


