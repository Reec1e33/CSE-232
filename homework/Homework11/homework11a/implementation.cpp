// WRITE YOUR CODE HERE
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "header.hpp"

std::string wordValue(std::string str1){
  std::string output = "";
  std::copy_if(str1.begin(), str1.end(), std::back_inserter(output), [](char ch) {return ch < 'a';});
  return output;
}

void SortByUppercase(std::vector<std::string> &vec){
  std::stable_sort(vec.begin(), vec.end(), [](std::string str1, std::string str2){return wordValue(str1) < wordValue(str2);});
}

std::string DoubleToPercentString(std::vector<double> &vec){

    std::vector<int> output2(vec.size());
    std::transform(vec.begin(), vec.end(), output2.begin(), [](double x){return static_cast<int>(x * 100);});
    std::string output = std::accumulate(output2.begin(), output2.end(),std::string{}, [](std::string a, int & x)
    {return a + std::to_string(x) + "%" + " ";});
    return output;
}


int main() {
    std::vector<std::string> words = {
        "wolf", "BanAna", "caRRot", "AprIcots", "BEets",
        "chiCkPeas", "orAngEs", "apple", "CAT", "dOG"
    };

    std::vector<std::string> expected = {
        "wolf", "apple", "orAngEs", "AprIcots", "BanAna",
        "BEets", "CAT", "chiCkPeas", "dOG", "caRRot"
    };

    // Apply the SortByUppercase function
    SortByUppercase(words);

    // Print results for debugging
    std::cout << "Sorted words:" << std::endl;
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    // Verify the result
    if (words == expected) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return 0;
}