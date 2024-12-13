#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "utility.hpp"

struct Portfolio {
  std::map<std::string, int> assets; // Tracks asset quantities for a user
};

struct OrderBook {
  std::vector<Order> buyOrders;  // List of buy orders for a specific asset
  std::vector<Order> sellOrders; // List of sell orders for a specific asset
};

class Exchange {
 private:
  // Encapsulated data
  std::map<std::string, Portfolio> userPortfolios; // User portfolios mapping username to assets
  std::map<std::string, OrderBook> marketOrders;   // Order books for each asset
  std::vector<Trade> tradeHistory;                 // History of executed trades

  // Helper function
  void MatchOrders(Order &newOrder, std::vector<Order> &oppositeOrders);
  
 public:
  // Member functions
  void MakeDeposit(const std::string &username, const std::string &asset, int amount);
  void PrintUserPortfolios(std::ostream &os) const;
  bool MakeWithdrawal(const std::string &username, const std::string &asset, int amount);
  bool AddOrder(const Order &order);
  void PrintUsersOrders(std::ostream &os) const;
  void PrintTradeHistory(std::ostream &os) const;
  void PrintBidAskSpread(std::ostream &os) const;
};
