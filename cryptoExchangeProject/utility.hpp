#pragma once

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <string>

struct Order {
    std::string username;
    std::string side;
    std::string asset;
    int amount;
    int price;
};

// Declare operator<<
std::ostream& operator<<(std::ostream& os, const Order& order);
bool operator==(const Order& lhs, const Order& rhs);



struct Trade {
  std::string buyer_username;
  std::string seller_username;
  std::string asset;
  int amount;
  double price;
};
