#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main() {
    string line;
    
    while(getline(std::cin, line)) {
        string output;
        string word;
        for (char ch : line ) {
           if (isspace(ch) == false){
            word += ch;


           }else{
                if (word.length() > 4) {
                    output = output + " " + word;
                    
                }
                word.clear();
           }
           
           
        }
        if (word.length() > 4) {
            output = output + " " + word;
           }
       

        
        cout << output << endl;
    }
           
}