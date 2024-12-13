#include "exchange.hpp"
#include <utility>
#include <algorithm>
#include <iomanip>
#include <iostream>

// Helper: Determine if order is taker
// The "order" passed to AddOrder is always the taker order.
// We already treat the new order as taker. No extra helper needed for now.

// MatchOrders tries to match as much of newOrder (taker) as possible with oppositeOrders (makers).
// Use the taker order's price for the trade price.
void Exchange::MatchOrders(Order& newOrder, std::vector<Order>& oppositeOrders) {
    auto it = oppositeOrders.begin();
    while (it != oppositeOrders.end() && newOrder.amount > 0) {
        bool canMatch = false;
        if (newOrder.side == "Buy" && newOrder.price >= it->price) {
            canMatch = true;
        } else if (newOrder.side == "Sell" && newOrder.price <= it->price) {
            canMatch = true;
        }

        if (canMatch) {
            int tradeAmount = std::min(newOrder.amount, it->amount);
            // Use taker order's price (newOrder) as trade price
            double tradePrice = newOrder.price; 

            std::cout << "Trade executed: " << tradeAmount << " " << newOrder.asset
                      << " at " << tradePrice << " USD between "
                      << (newOrder.side == "Buy" ? newOrder.username : it->username)
                      << " and " << (newOrder.side == "Buy" ? it->username : newOrder.username)
                      << std::endl;

            // Since buyer/seller already "paid" upfront, we just do final distribution
            if (newOrder.side == "Buy") {
                // Buyer gets asset
                MakeDeposit(newOrder.username, newOrder.asset, tradeAmount);
                // Seller gets USD
                MakeDeposit(it->username, "USD", tradeAmount * (int)tradePrice);
            } else {
                // Seller gets USD
                MakeDeposit(newOrder.username, "USD", tradeAmount * (int)tradePrice);
                // Buyer gets asset
                MakeDeposit(it->username, newOrder.asset, tradeAmount);
            }

            // Record the trade in history using taker price
            tradeHistory.push_back({
                (newOrder.side == "Buy" ? newOrder.username : it->username),
                (newOrder.side == "Buy" ? it->username : newOrder.username),
                newOrder.asset,
                tradeAmount,
                tradePrice
            });

            newOrder.amount -= tradeAmount;
            it->amount -= tradeAmount;

            if (it->amount == 0) {
                it = oppositeOrders.erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
}


void Exchange::MakeDeposit(const std::string &username, const std::string &asset, int amount) {
    if (userPortfolios.find(username) == userPortfolios.end()) {
        userPortfolios[username] = Portfolio();
    }
    if (userPortfolios.at(username).assets.find(asset) == userPortfolios.at(username).assets.end()) {
        userPortfolios.at(username).assets[asset] = 0;
    }
    userPortfolios.at(username).assets.at(asset) += amount;
}

void Exchange::PrintUserPortfolios(std::ostream &os) const {
    os << "User Portfolios (in alphabetical order):\n";
    for (const auto &[username, portfolio] : userPortfolios) {
        os << username << "'s Portfolio: ";
        for (const auto &[asset, amount] : portfolio.assets) {
            if (amount > 0) {
                os << amount << " " << asset << ", ";
            }
        }
        os << "\n";
    }
}

bool Exchange::MakeWithdrawal(const std::string &username, const std::string &asset, int amount) {
    if (userPortfolios.find(username) == userPortfolios.end() ||
        userPortfolios.at(username).assets.find(asset) == userPortfolios.at(username).assets.end()) {
        return false; 
    }

    auto &portfolio = userPortfolios.at(username).assets;
    if (portfolio.at(asset) < amount) {
        return false;  
    }
    portfolio.at(asset) -= amount;
    if (portfolio.at(asset) == 0) {
        portfolio.erase(asset); 
    }
    return true;
}

bool Exchange::AddOrder(const Order& order) {
    // Validate user has enough to cover entire order upfront
    if (order.side == "Buy") {
        int totalCost = order.amount * order.price;
        if (!MakeWithdrawal(order.username, "USD", totalCost)) {
            std::cout << "Order rejected: " << order.username << " does not have enough USD\n";
            return false;
        }
    } else { // Sell
        if (!MakeWithdrawal(order.username, order.asset, order.amount)) {
            std::cout << "Order rejected: " << order.username << " does not have enough " << order.asset << "\n";
            return false;
        }
    }

    // Taker order
    Order modifiableOrder = order;
    if (order.side == "Buy") {
        MatchOrders(modifiableOrder, marketOrders[order.asset].sellOrders);
    } else {
        MatchOrders(modifiableOrder, marketOrders[order.asset].buyOrders);
    }

    // Unmatched portion becomes a maker order
    if (modifiableOrder.amount > 0) {
        if (modifiableOrder.side == "Buy") {
            marketOrders[modifiableOrder.asset].buyOrders.push_back(modifiableOrder);
        } else {
            marketOrders[modifiableOrder.asset].sellOrders.push_back(modifiableOrder);
        }
    }

    return true;
}


void Exchange::PrintUsersOrders(std::ostream &os) const {

    os << "Users Orders (in alphabetical order):\n";
    for (const auto &[username, portfolio] : userPortfolios) {
        os << username << "'s Open Orders (in chronological order):\n";

        for (const auto &[asset, orderBook] : marketOrders) {
            for (const auto &order : orderBook.buyOrders) {
                if (order.username == username && order.amount > 0) {
                    os << "Buy " << order.amount << " " << asset << " at "
                       << order.price << " USD by " << username << "\n";
                }
            }
            for (const auto &order : orderBook.sellOrders) {
                if (order.username == username && order.amount > 0) {
                    os << "Sell " << order.amount << " " << asset << " at "
                       << order.price << " USD by " << username << "\n";
                }
            }
        }

        os << username << "'s Filled Orders (in chronological order):\n";
        for (const auto &trade : tradeHistory) {
            bool isBuyer = (trade.buyer_username == username);
            bool isSeller = (trade.seller_username == username);
            if (isBuyer || isSeller) {
                std::string side = isBuyer ? "Buy" : "Sell";
                os << side << " " << trade.amount << " " << trade.asset
                   << " at " << (int)trade.price << " USD by " << username << "\n";
            }
        }
    }
}

// Updated PrintTradeHistory to match test #11 and beyond:
// Format: 
// "Trade History (in chronological order):\n"
// For each trade: "<Buyer> Bought <amount> of <asset> From <Seller> for <price> USD\n"
void Exchange::PrintTradeHistory(std::ostream &os) const {
    os << "Trade History (in chronological order):\n";
    for (const auto &trade : tradeHistory) {
        // Buyer Bought X of Asset From Seller for Price USD
        os << trade.buyer_username << " Bought " << trade.amount << " of " 
           << trade.asset << " From " << trade.seller_username
           << " for " << (int)trade.price << " USD\n";
    }
}

void Exchange::PrintBidAskSpread(std::ostream &os) const {
    os << "Bid-Ask Spread:\n";
    for (const auto &entry : marketOrders) {
        const auto &asset = entry.first;
        const auto &orderBook = entry.second;

        if (orderBook.buyOrders.empty() || orderBook.sellOrders.empty()) {
            continue;
        }

        auto highestBid = std::max_element(
            orderBook.buyOrders.begin(), orderBook.buyOrders.end(),
            [](const Order &a, const Order &b) { return a.price < b.price; });
        auto lowestAsk = std::min_element(
            orderBook.sellOrders.begin(), orderBook.sellOrders.end(),
            [](const Order &a, const Order &b) { return a.price < b.price; });

        os << asset << ": Bid $" << highestBid->price << " | Ask $"
           << lowestAsk->price << "\n";
    }
}
