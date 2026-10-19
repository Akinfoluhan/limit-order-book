#include <iostream>
#include "Order.hpp"
#include "PriceLevel.hpp"

int main()
{
    Order order1{
        1,
        Side::Buy,
        10000,
        10};

    Order order2{
        2,
        Side::Sell,
        10000,
        25};

    PriceLevel level{
        10000};

    level.addOrder(order1);
    level.addOrder(order2);

    std::cout << "Price: " << level.price << "\n";
    std::cout << "Number of Orders: " << level.orders.size() << "\n";
    std::cout << "Total Quantity: " << level.totalQuantity << "\n";

    return 0;
}
