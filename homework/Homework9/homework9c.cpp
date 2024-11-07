// WRITE YOUR CODE HERE

#include "header9b.h"

void CopyStockPrices(double * source, double * destination){
  int iter = *source;

  while(iter != -1){
    *destination = *source;
    
    ++destination;
    ++source;
    --iter;

  }
}