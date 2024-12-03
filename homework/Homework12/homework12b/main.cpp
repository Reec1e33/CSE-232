// WRITE YOUR CODE HERE
#include <random>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>



int main(){
    

    std::string input{""};
    std::getline(std::cin, input);
    
    int num = 0;
    std::uniform_int_distribution<int> dist(10,99);
    while (num <= 1000){
        std::mt19937_64 gen(num);
        

        std::stringstream os;
        for (int i = 0; i < 10; ++i){
            os << dist(gen) << " ";
        }
        if (num == 0){
            input += " ";
        }
        if (os.str() == input){
          
            std::cout << "Seed: " << num;
            std::cout << std::endl;

            for(int i = 10; i < 20; ++i){
                os << dist(gen) << " ";
            }
            std::cout << os.str();
            break;
        }
        if (num == 0){
            input.pop_back();
        }

        ++num;
        
    }


    
    return 0;
    
}