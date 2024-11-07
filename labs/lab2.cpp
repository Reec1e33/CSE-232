#include <iostream>



int findSum(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

void additativeSum(int num) {
  if (num < 10) {
    std::cout << "0 " << num << std::endl;
    return;
  }
  int numPersistence = 0;
  while (num >= 10) {
    num = findSum(num);
    ++numPersistence;
  }
  std::cout << numPersistence << " " << num << std::endl;
  }

int main() {
  // WRITE YOUR CODE HERE
    int num;
    while(std::cin >> num) {

      
      if (num < 0) {
        break;
      }
      additativeSum(num);
    }
    return 0;
  }

