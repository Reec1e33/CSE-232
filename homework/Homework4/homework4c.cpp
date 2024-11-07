#include <iostream>


double Centrifuge( int &time, int &ore, double *u_238) {
  int cycles{ore / 10};
  double u_235{0};
  
  int i = 0;
  while ( i < cycles) {
    time = time - 12;
    
    if (time < 0) {
      time = time + 12;
      ore = ore-(i*10);
      return u_235;
      break;
    }
    
    *u_238 += .993;
    u_235 += .007;
    ++i;
  }
  ore = ore % 10; 
  
  
  
  
  return u_235;




}