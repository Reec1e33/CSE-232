#include <iostream>
#include <sstream>
#include <cassert>
#include "exchange.hpp"

int main() {
    Exchange e;

    // Initial setup
    e.MakeDeposit("Nahum", "BTC", 10);
    e.MakeDeposit("Dolson", "USD", 5555);

    // Verify initial state
    std::ostringstream oss;
    e.PrintUserPortfolios(oss);
    assert(oss.str() == "User Portfolios (in alphabetical order):\nDolson's Portfolio: 5555 USD, \nNahum's Portfolio: 10 BTC, \n");
    std::cout << "Initial setup passed.\n";

    // Add orders
    assert(e.AddOrder({"Nahum", "Sell", "BTC", 5, 100}));
    assert(e.AddOrder({"Dolson", "Buy", "BTC", 5, 100}));

    // Verify final state
    oss.str("");
    e.PrintUserPortfolios(oss);
    std::string expected =
        "User Portfolios (in alphabetical order):\n"
        "Dolson's Portfolio: 5 BTC, 5055 USD, \n"
        "Nahum's Portfolio: 5 BTC, 500 USD, \n";
    if (oss.str() == expected) {
        std::cout << "Exact Price Complete Trades Test Passed!" << std::endl;
    } else {
        std::cout << "Exact Price Complete Trades Test Failed!" << std::endl;
        std::cout << "Expected:\n" << expected << "\nGot:\n" << oss.str();
    }

    return 0;
}
