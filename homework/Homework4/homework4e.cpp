#include <iostream>
#include <string>

char * Sandwich(std::string & line, char * bread_ptr) {

// WRITE YOUR CODE HERE

    for (std::string::size_type i = 0; i < line.size()-2; ++i) {
        if (line.at(i) == *bread_ptr && line.at(i+2) == *bread_ptr) {
            return &line.at(i+1);
        }
    }   
    
    return nullptr;
}   
int main() {
	std::string line = "Char is a character";
	char bread = 'a';
	char * filling_ptr = Sandwich(line, &bread);
  *filling_ptr = 'Z';
	std::cout << line << std::endl; // Should be r


}