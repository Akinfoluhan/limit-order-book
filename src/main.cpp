#include <iostream>
#include "Order.hpp"
#include "PriceLevel.hpp"
#include "OrderBook.hpp"

int main()
{
    OrderBook book;

    book.addOrder({1,
                   Side::Buy,
                   10000,
                   10});

    book.addOrder({2,
                   Side::Buy,
                   10100,
                   5});

    book.addOrder({3,
                   Side::Sell,
                   10300,
                   20});

    book.addOrder({4,
                   Side::Sell,
                   10200,
                   15});

    auto bestBid = book.bestBid();
    auto bestAsk = book.bestAsk();

    if (bestBid)
    {
        std::cout << "Best Bid: " << *bestBid << std::endl;
    }

    if (bestAsk)
    {
        std::cout << "Best Ask: " << *bestAsk << std::endl;
    }

    return 0;
}
