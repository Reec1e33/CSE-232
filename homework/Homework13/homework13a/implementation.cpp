// WRITE YOUR CODE HERE
// WRITE YOUR CODE HERE
#include <list>
#include <iterator>
#include "header.hpp"

int center(std::list<int>::const_iterator start, std::list<int>::const_iterator end ){
    if (std::next(start) == end){
        return *start;
    }
    return center(std::next(start), std::prev(end));
}