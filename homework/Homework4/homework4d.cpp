#include <string>
#include <iostream>

using std::string;

string SharedLetters(string const &str1, string const str2, string const * str3) {
    string output{};

    string strThree = *str3;
    string strOne = str1;
    string strTwo = str2;
    std::string::size_type index{};
    if (str1.size() > str2.size()){
        if (str1.size() > strThree.size()) {
            index = str1.size();
        }else{
            index = strThree.size();
        }
    }else if (str2.size() > strThree.size()) {
        index = str2.size();
    }else{
        index = strThree.size();
    }
    strOne.resize(index, 'x');
    strTwo.resize(index, 'y');
    strThree.resize(index,'z' );
    for (int i = 0; i < index; ++i) {
        if ( strOne.at(i) == strTwo.at(i) && strTwo.at(i) == strThree.at(i) && strOne.at(i) == strThree.at(i)){
            output += "3,";
            
        }else if ((strOne.at(i) == strTwo.at(i)) || (strOne.at(i) == strThree.at(i)) || (strTwo.at(i) == strThree.at(i)) ) {
            output += "1,";
            
        


            

        }else{
            output += "0,";
        }
    }
    return output;

    
}

int main() {
    string s1,s2,s3;

    std::cin >> s1;
    std::cin >> s2;
    std::cin >> s3;
    std::cout << SharedLetters(s1,s2, &s3);
}