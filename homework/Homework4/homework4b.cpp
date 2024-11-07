// WRITE YOUR CODE HERE

#include <iostream>
#include <cctype>
#include <string>
using std::string;

void To_Digits(string & s) {
    string word{s};
    for (char & ch : word){
        ch = tolower(ch);
    }
    string output{""};
    string last{""};
    int diff{0};
    for (std::string::size_type i = 0; i < s.size(); ++i ) {
        
        last += tolower(s.at(i));
        if (word.substr(i-diff,4) == "zero"){
            output = "0";
            s.replace(i,4,output);
            last.clear();
            
        } else if (word.substr(i-diff,3) == "one") {
            output = "1";
            s.replace(i,3,output);
            last.clear();
            

           
        } else if (word.substr(i-diff,3)== "two") {
            output = "2";
            s.replace(i,3,output);
            last.clear();
            
            

        } else if (word.substr(i-diff,5) == "three") {
            output = "3";
            s.replace(i,5,output);
            last.clear();
            
            

        } else if (word.substr(i-diff,4) == "four") {
            output = "4";
            s.replace(i,4,output);
            last.clear();
          
            

        } else if (word.substr(i-diff,4) == "five") {
            output = "5";
            s.replace(i,4,output);
            last.clear();
            

        }else if (word.substr(i-diff,3) == "six") {
            output = "6";
            s.replace(i,3,output);
            last.clear();
           

        }else if (word.substr(i-diff,5) == "seven") {
            output = "7";
            s.replace(i,5,output);
            last.clear();
            

        }else if (word.substr(i-diff,5) == "eight") {
            output = "8";
            s.replace(i,5,output);
            last.clear();


        }else if (word.substr(i-diff,4) == "Nine") {
            output = "9";
            s.replace(i,4,output);
            last.clear();  


        }

        
        diff = (s.size() - word.size());
    }

    if (last != "") {
        if (last == "one") {
            s.replace(s.size()-3,3,"1");
        }else if (last == "two") {
            s.replace(s.size()-3,3,"2");
        }else if (last == "three") {
            s.replace(s.size()-5,5,"3");
        }else if (last == "four") {
            s.replace(s.size()-4,4,"4");
        }else if (last == "five") {
            s.replace(s.size()-4,4,"5");
        }else if (last == "six") {
            s.replace(s.size()-3,3,"6");
        }else if (last == "seven") {
            s.replace(s.size()-5,5,"7");
        }else if (last == "eight") {
            s.replace(s.size()-5,5,"8");
        }else if (last == "nine") {
            s.replace(s.size()-4,4,"9");
        }
        
    }
    
}


int main() {
    string text = "It began with the forging of the Great Rings. Three were given to the Elves, immortal, wisest and fairest of all beings. Seven to the Dwarf-Lords, great miners and craftsmen of the mountain halls. And nine, nine rings were gifted to the race of Men, who above all else desire power. For within these rings was bound the strength and the will to govern each race. But they were all of them deceived, for another ring was made. Deep in the land of Mordor, in the Fires of Mount Doom, the Dark Lord Sauron forged a master ring, and into this ring he poured his cruelty, his malice and his will to dominate all life. One ring to rule them all.";
   

    To_Digits(text);
    std::cout << text << std::endl; // Output: 3 Rings for the Elven-kings under the sky, 7 for the Dwarf-lords.
    return 0;
}
