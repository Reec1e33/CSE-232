// WRITE YOUR CODE HERE
#include <string>
#include <iostream>
#include <sstream>


std::string checker(std::string & input, std::string & input2){
    std::string output2 = ".....";
    for (std::string::size_type i = 0; i < input.size(); ++i){
        if (input.at(i) == input2.at(i)){
            output2.at(i) = input.at(i);
        }else if( input.find(input2.at(i)) != std::string::npos){
            output2.at(i) = '?';
        }
    }
    return output2;
}







int main(){
  std::string input;
  int guesses = 0;
  std::cout << "Give me a secret word: ";
  std::cin >> input;
  std::cout << std::endl;
  std::string input2;
  std::string output;

  while((std::cin >> input2) && guesses < 6){
    
    output = checker(input, input2);
    std::cout << "Give me a guess: ";
    std::cout << std::endl;
    std::cout << output << std::endl;
    if (output == input){

        std::cout << "You Win!" << std::endl;
        return 0;
    }
    ++guesses;
    
    
  }
  if (guesses < 5){
    std::cout << "Give me a guess: ";
    std::cout << std::endl;
  }

  std::cout << "You Lose." << std::endl;
  return 0;
}