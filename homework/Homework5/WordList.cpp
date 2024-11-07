// WRITE YOUR CODE HERE
#include "WordList.h"
#include <iostream>

bool AtListPosition(std::string const &wordList, std::string const &word, std::string::size_type position) {
  std::string checkWord;
  if (word == wordList){
    return true;
  }
  bool commaBehind = (position + word.size() < wordList.size() && wordList.at(position + word.size()) == ',');  
  bool commaInFront = (position > 0 && wordList.at(position - 1) == ',');
  bool startOfString = (position == 0);
  bool end ( position + word.size() == wordList.size());
  
  if (wordList.substr(position, word.size()) == word) {
    if ((commaBehind && commaInFront) || (commaBehind && startOfString) || (end && commaInFront)){
      return true;
    }else{
     return false;
    }
    
  }else{
    return false;
  }
    
 
}



std::string::size_type FindInList(std::string const &wordList, std::string const &word, std::string::size_type position) {
  if (word.size() > wordList.size()) {
    return std::string::npos;
  }
  for (std::string::size_type i = position; i <= wordList.size() - word.size(); ++i) {
    if (wordList.substr(i,word.size()) == word) {
      if (AtListPosition(wordList, word, i)){
        return i;
      }
      
      
    }
  }
  
  return std::string::npos;
}


std::string GetFirstInList(std::string const &wordList, std::string * str1, std::string * str2) {
  std::string::size_type position1 = FindInList(wordList, *str1);
  std::string::size_type position2 = FindInList(wordList, *str2);

  if (position1 == std::string::npos && position2 != std::string::npos){
    return *str2;
  }else if(position1 != std::string::npos && position2 == std::string::npos){
    return *str1;
  }else{
    if (position1 > position2) {
        return *str2;
    }else if (position2 > position1){
        return *str1;
    }
  }
  return "N/A";
  
}

size_t CountInList(std::string const &wordList, std::string const &word) {
  int count{0};
  std::string::size_type i = 0;
  if (wordList == word) {
    return 1;

  }
  if (word.size() > wordList.size()) {
    return 0;
  }
  while ( i <= wordList.size() - word.size()) {
    if (wordList.substr(i,word.size()) == word) {
        bool startsAtBeggining = (i==0);
        bool precededByComma = (i > 0 && wordList.at(i-1) == ',');
        
        bool endOfString = (i + word.size() == wordList.size());
        bool followedByComma = (!endOfString && wordList.at(i+word.size()) == ',');

        if ((startsAtBeggining && followedByComma) || (endOfString && precededByComma) || (precededByComma && followedByComma)){
            count += 1;
        }
    }
    i++;

  }
  
  return count;
}

