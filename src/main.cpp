#include <iostream>

#include "OrderBook.hpp"

int main()
{
    OrderBook book;

    book.addOrder({1,
                   Side::Sell,
                   10000,
                   5});

    book.addOrder({2,
                   Side::Sell,
                   10100,
                   8});

    book.addOrder({3,
                   Side::Sell,
                   10200,
                   10});

    auto trades = book.addOrder({4,
                                 Side::Buy,
                                 10200,
                                 15});

    for (const Trade &trade : trades)
    {
        std::cout << "Buy Order: " << trade.buyOrderId
                  << ", Sell Order: " << trade.sellOrderId
                  << ", Quantity: " << trade.quantity
                  << ", Price: " << trade.price
                  << "\n";
    }

    return 0;
}