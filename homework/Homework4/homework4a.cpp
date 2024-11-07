// WRITE YOUR CODE HERE
#include <iostream>
int Triple(int value) { 
  return value * 3; 
}

int Closest_Multiple_Of_13(int num) {
  int output1 = 0;
  int output2 = 0;

  int i = 0;
  int index1 = 0, index2 = 0;
  while (true) {
    if (((num + i) % 13) == 0) {
      output1 = num + i;
      index1 = i;
      break;
    }
    ++i;
  }
  i = 0;
  while (true) {
    if (((num - i) % 13) == 0) {
      output2 = num - i;
      index2 = i;
      break;
    }
    ++i;
  }
  std::cout << output1 << std::endl;
  std::cout << output2 << std::endl;
  if ((num - index1) > (num - index2)) {
    return output1;
  } else {
    return output2;
  }
}

int main() {
  int x;
  std::cin >> x;

  std::cout << x * 2 << std::endl;
}