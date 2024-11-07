// WRITE YOUR CODE HERE

#include "header9b.h"

void CopyStockPrices(double * source, double * destination){

  while(true){
    if (*source < 0){
      *destination = *source;
      break;
    }else{
      *destination = *source;
    }
    
    ++destination;
    ++source;

  }
}