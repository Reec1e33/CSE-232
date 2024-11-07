
#include <vector>
#include "ForgetfulVector.hpp"

int ForgetfulVector::size(){
    return vec2.size();
}

size_t ForgetfulVector::at(int const & num){
    return vec2.at(num);
}

void ForgetfulVector::push_back(int const & num){
    vec.push_back(num);
    int count;
    for (size_t i = 0; i < vec.size(); ++i){
        count = 0;
        for (size_t j = 0; j < vec.size(); ++j) {
            if ((vec.at(i) == vec.at(j)) && (i != j)){
                count += 1;
            }
        }
    }
    if ( count >= 1){
        vec2.push_back(num);
    }
    

    
}