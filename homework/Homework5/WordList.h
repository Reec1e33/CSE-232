#pragma once

#include <string>



bool AtListPosition(std::string const &wordList, std::string const &word, std::string::size_type position);

std::string::size_type FindInList(std::string const &wordList, std::string const &word, std::string::size_type position = 0);


std::string GetFirstInList(std::string const &wordList, std::string * str1, std::string * str2);


size_t CountInList(std::string const &wordList, std::string const &word);




