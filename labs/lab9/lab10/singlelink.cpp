#include<iostream>
#include<sstream>
#include<stdexcept>
#include<string>
#include <algorithm>

#include "singlelink.hpp"



SingleLink::SingleLink() : head_{nullptr}, tail_{nullptr} {}      
SingleLink::SingleLink(int dat) {
    head_ = new Node(dat); 
    tail_ = head_;        
}
SingleLink::~SingleLink() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next_; 
        delete current;               
        current = next;             
    }
}



void SingleLink::append_back(int dat) {
    Node* node = new Node(dat); 

    if (head_ == nullptr) {     
        head_ = node;             // Set both head and tail to the new node
        tail_ = node;
    } else {
        tail_->next_ = node;      // Link the new node at the end of the list
        tail_ = node;             // Update tail to the new node
    }
}

std::ostream & operator<<(std::ostream &out, const SingleLink &s){
    Node node = *s.head_;

    while (node.next_ != nullptr){
        out << node.data_ << ", ";
        node =  *node.next_;
    }
    out << node.data_  << ", ";
    return out;
}


Node& SingleLink::operator[](size_t index){
    size_t find = 0;
    Node * start = head_;
    
    while (find != index ){
        start->next_ = start;
        ++find;
    }
    
    return * start;

}

