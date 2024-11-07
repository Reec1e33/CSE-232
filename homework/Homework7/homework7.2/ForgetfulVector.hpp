#pragma once
#include <vector>
using std::vector;

class ForgetfulVector{
    
    vector<int> vec;
    vector<int> vec2;
public:
    ForgetfulVector(vector<int> vec1) : vec{vec1} {}
    ForgetfulVector() : vec({}) {}

    int size();
    size_t at(int const & num);
    void push_back(int const & num);
    
};