#include "homework6a.hpp"
#include <vector>
#include <iostream>

std::vector<int> SumByIndex(std::vector<std::vector<int>> const & vector2D) {



    if (vector2D.size() == 1) {
      return vector2D.at(0);
    }
    size_t length = 0;
    for (std::vector<int> v : vector2D) {
        if (v.size() > length){
            length = v.size();
        }
    }
    std::vector<int> vector1D(length, 0);

    for (size_t i = 0; i < vector2D.size(); ++i){
        
        for (size_t j = 0; j < vector2D.at(i).size(); ++j){
            
            vector1D.at(j) += vector2D.at(i).at(j);
            


        }
    }

    return vector1D;
}


