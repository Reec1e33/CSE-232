#include <string>
#include <iostream>
#include <vector>
using std::string, std::vector, std::cout, std::cin;

int main(){
    string input1;
    string input2;
    cin >> std::noskipws;
    cin >> input1;
    cin >> input2;

    
    vector<string> hpList{{}};
    vector<string> pokeList{{}};

    string word;

    for (string::size_type i = 0; i < input1.size(); ++i){
        if (input1.at(i) == ',' || input1.at(i) == ':'){
            
            word += input1.at(i);
            pokeList.push_back(word);
            word = "";
        }else{
            word += input1.at(i);
        }
    }
    word = "";

    for (string::size_type i = 0; i < input2.size(); ++i){
        
        if (input2.at(i) == ','|| input2.at(i) == ':'){
            word += input2.at(i);
            hpList.push_back(word);
            word = "";
        }else{
            word += input2.at(i);
        }
    }


    
    

    for (size_t i = 0; i < (pokeList.size()); ++i){
        if (i == 1){
            hpList.at(1).pop_back();
            hpList.at(1).push_back(',');
            pokeList.at(1).pop_back();
            pokeList.at(1).push_back(',');
        }
        std::cout << pokeList.at(i)  << hpList.at(i) <<  std::endl;
    }
    int biggest = 0;
    int index = 0;
    for (size_t i = 2; i < hpList.size(); ++i){
        if (std::stoi(hpList.at(i).substr(0,hpList.at(i).size()-1)) > biggest){
            biggest = std::stoi(hpList.at(i).substr(0,hpList.at(i).size()-1));
            index = i;
        }
    }
    cout << std::endl;
    std::cout << "Max:" << std::endl;
    std::cout << pokeList.at(index) << hpList.at(index) << std::endl;
}