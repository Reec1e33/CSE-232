#include "header.hpp"

void Stack::push(char c) {
    Node* new_top = new Node(c);
    new_top->down = top_;
    top_ = new_top;
}

char Stack::top() { 
    return top_->letter; 
}

void Stack::pop() {
    Node* new_top = top_->down;
    delete top_;
    top_ = new_top;
}

void Stack::clear(){
  while (top_ != nullptr){
    pop();
   }


}

bool Stack::isEmpty() {
    return top_ == nullptr;
}

std::ostream& operator<<(std::ostream& os, Stack const& s) {
    Node* current = s.top_;
    while (current != nullptr) {
        os << current->letter << ",";
        current = current->down;
    }
    return os;
}

Stack::~Stack() {
   clear();
}

Stack::Stack(Stack const& other) : top_(nullptr) {
    if (other.top_ == nullptr) return;

    Stack temp;
    for (Node* current = other.top_; current != nullptr; current = current->down) {
        temp.push(current->letter); 
    }

    for (Node* current = temp.top_; current != nullptr; current = current->down) {
        push(current->letter);
    }
}

Stack& Stack::operator=(Stack other) {
    std::swap(top_, other.top_);
    return *this;
}