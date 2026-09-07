#include <iostream>
#include "Order.hpp"

int main()
{
    Order order{
        1,
        Side::Buy,
        100,
        10};

    std::cout << "Order ID: " << order.id << "\n";
    std::cout << "Side: " << (order.side == Side::Buy ? "Buy" : "Sell") << "\n";
    std::cout << "Price: " << order.price << "\n";
    std::cout << "Quantity: " << order.quantity << "\n";

    return 0;
}
