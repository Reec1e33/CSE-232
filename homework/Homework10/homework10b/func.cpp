#include "func.hpp"

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>

std::set<std::string> ReplacementCensor(
    std::istream& is, std::ostream& os,
    std::map<std::string, std::string>& mapWords) {
  std::set<std::string> output;
  std::string word = "";
  bool firstword = true;
  while (is >> word) {
    if (firstword == false){
        os << " ";
    }
    std::string wordCompare = "";


    for( char ch : word){
        wordCompare += tolower(ch);
    }

    for (const auto& pair : mapWords) {
        const std::string& key = pair.first;
        const std::string& replacement = pair.second;
        std::string rep2 = "";
        std::string key2 = "";

        for (char ch : key){
            key2 += tolower(ch);
        }

        size_t pos = wordCompare.find(key2);
        if (pos != std::string::npos) {
            output.insert(word.substr(pos, key.size()));

            word.replace(pos, key.size(), replacement);

            wordCompare.replace(pos, key.size(), replacement);
        }

    }

    os << word;
    
    firstword = false;
  }
  return output;
}



int main() {
    // Test case setup
    std::map<std::string, std::string> bad_to_good = {{"word", "Grouped-Letter-Unit"}, {"be", "wasp"}, {"not found", "not appearing"}, {"PlaCe", "LoCation"}};
    std::istringstream iss("note: this is a line with multiple WORds that should be rePLACEd./n all instances of word eveninlargerWordsshould be repLAced.");
    std::ostringstream oss;

    // Call ReplacementCensor
    std::set<std::string> result = ReplacementCensor(iss, oss, bad_to_good);

    // Print the resulting set
    std::cout << "Resulting set of replaced words: { ";
    for (const auto& word : result) {
        std::cout << word << " ";
    }
    std::cout << "}" << std::endl;

    // Print the modified output string
    std::cout << "Output string: " << oss.str() << std::endl;

    return 0;
}