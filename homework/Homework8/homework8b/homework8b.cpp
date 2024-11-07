// WRITE YOUR CODE HERE
#include "homework8b.h"
#include <iostream>
#include <vector>


bool AreRoadsBalanced(std::vector<std::vector<bool>> road_map){
  std::vector<int> vecIn{{}};
  std::vector<int> vecOut{{}};
  vecOut.resize(road_map.size());
  vecIn.resize(road_map.size());
  
 
  for (size_t i = 0; i < road_map.size(); ++i){
    for (size_t j = 0; j < road_map.at(i).size(); ++j){
      
      if((road_map.at(i).at(j) == true) && (i != j)){
        vecIn.at(j) += 1;
        vecOut.at(i) += 1;
        
        
      }
    }
  }
  for (size_t i = 0; i < vecIn.size(); ++i){
    if (vecIn.at(i) == 0){
        return false;
    }else if(vecOut.at(i) < vecIn.at(i)){
        return false;
    }

  }


  return true;
}