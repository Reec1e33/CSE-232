// WRITE YOUR CODE HERE

#pragma once

#include <stack>
template <typename T>
std::stack<T> reverse_stack(std::stack<T>  & stack1){
    std::stack<T> reversed;
    while (!(stack1.empty())){
        reversed.push(stack1.top());
        stack1.pop();
    }
    return reversed;
}
