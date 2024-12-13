#include "utility.hpp"

// Definition of operator<< for printing
std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << order.side << " " << order.amount << " " << order.asset
       << " at " << order.price << " USD by " << order.username;
    return os;
}

// Definition of operator== for equality comparison
bool operator==(const Order& lhs, const Order& rhs) {
    return lhs.username == rhs.username &&
           lhs.side == rhs.side &&
           lhs.asset == rhs.asset &&
           lhs.amount == rhs.amount &&
           lhs.price == rhs.price;
}
