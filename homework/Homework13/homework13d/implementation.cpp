#include "header.hpp"

void Flip(Node* node) {
    if (node == nullptr) {
        return; 
    }
    
    node->on = !node->on; 
    
    Flip(node->next); 
}
